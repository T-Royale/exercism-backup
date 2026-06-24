#include "two_bucket.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    bucket_liters_t a;
    bucket_liters_t b;
    int parent;
} Node;

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
int mcd(int a, int b);

bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_volume, bucket_id_t start_bucket) {
    bucket_result_t result = {0};
    if (goal_volume > MAX(bucket_1_size, bucket_2_size) || (goal_volume % mcd(bucket_1_size, bucket_2_size) != 0)) {
        result.possible = false;
        return result;
    }

    size_t queue_size = 64;
    Node *queue = calloc(queue_size, sizeof(Node));
    if (!queue) {
        perror("calloc");
        return (bucket_result_t){0};
    }
    bool visited[129][129] = {false};

    size_t front = 0;
    size_t rear = 0;

    {
        Node start = {0, 0, -1};
        if (start_bucket == BUCKET_ID_1) {
            start.a = bucket_1_size;
        } else
            start.b = bucket_2_size;
        queue[rear++] = start;
        visited[start.a][start.b] = true;

        if (start.a == goal_volume || start.b == goal_volume) {
            result.possible = true;
            result.goal_bucket = start.a == goal_volume ? BUCKET_ID_1 : BUCKET_ID_2;
            result.other_bucket_liters = start.a == goal_volume ? start.b : start.a;
            result.move_count = 1;
            goto exit;
        }
    }

    while (front < rear) {
        Node current = queue[front];

        if (rear >= queue_size - 6) {
            queue_size *= 2;
            Node *tmp = realloc(queue, sizeof(Node) * queue_size);
            if (!tmp) {
                free(queue);
                perror("realloc");
                return (bucket_result_t){0};
            }
            queue = tmp;
        }
        // 6 possible states
        Node new[6] = {0};
        // Pouring one bucket into the other bucket until either: a) the first bucket is empty b) the second bucket is full
        // Pouring 1 into 2
        int pour = MIN(current.a, bucket_2_size - current.b);
        new[0] = current;
        new[0].a -= pour;
        new[0].b += pour;
        // Pouring b into a
        pour = MIN(current.b, bucket_1_size - current.a);
        new[1] = current;
        new[1].b -= pour;
        new[1].a += pour;
        // Emptying a bucket and doing nothing to the other.
        // Empty a
        new[2] = current;
        new[2].a = 0;
        // Empty b
        new[3] = current;
        new[3].b = 0;
        // Filling a bucket and doing nothing to the other.
        // Fill a
        new[4] = current;
        new[4].a = bucket_1_size;
        // Fill b
        new[5] = current;
        new[5].b = bucket_2_size;

        for (int i = 0; i < 6; i++) {
            new[i].parent = front;

            if (start_bucket == BUCKET_ID_1) {
                if (new[i].a == 0 && new[i].b == bucket_2_size) continue;
            } else {
                if (new[i].b == 0 && new[i].a == bucket_1_size) continue;
            }

            if (new[i].a == goal_volume) {
                result.possible = true;
                result.goal_bucket = BUCKET_ID_1;
                result.other_bucket_liters = new[i].b;
                result.move_count = 1;
                int pos = new[i].parent;
                while (pos > -1) {
                    pos = queue[pos].parent;
                    result.move_count++;
                }
                goto exit;
            } else if (new[i].b == goal_volume) {
                result.possible = true;
                result.goal_bucket = BUCKET_ID_2;
                result.other_bucket_liters = new[i].a;
                result.move_count = 1;
                int pos = new[i].parent;
                while (pos > -1) {
                    pos = queue[pos].parent;
                    result.move_count++;
                }
                goto exit;
            } else {
                if (!visited[new[i].a][new[i].b]) {
                    queue[rear++] = new[i];
                    visited[new[i].a][new[i].b] = true;
                }
            }
        }
        front++;
    }
exit:
    free(queue);
    return result;
}

int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}
