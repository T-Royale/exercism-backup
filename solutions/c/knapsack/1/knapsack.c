#include "knapsack.h"
#include <stdlib.h>

#define MAX(a, b) ((a > b) ? a : b)

unsigned int maximum_value(unsigned int maximum_weight, item_t *items, unsigned int item_count) {
    if (!items || item_count == 0 || maximum_weight == 0) return 0;
    unsigned int *dp = calloc(maximum_weight + 1, sizeof(int));
    if (!dp) return 0;

    for (unsigned int item = 0; item < item_count; item++) { // Por cada item
        unsigned int weight = items[item].weight;
        unsigned int value = items[item].value;
        if (weight > maximum_weight) continue;

        // Para cada peso descubierto (hacia atrás para evitar duplicados)
        for (unsigned int w = maximum_weight; w >= weight; w--) {
            // A medida que aparecen nuevos items, ver si renta pillarlos o no
            dp[w] = MAX(dp[w], dp[w - weight] + value);
        }
    }

    unsigned int result = dp[maximum_weight];
    free(dp);
    return result;
}
