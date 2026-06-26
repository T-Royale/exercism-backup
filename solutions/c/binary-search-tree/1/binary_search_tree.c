#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

static node_t *new_node(int data) {
    node_t *result = malloc(sizeof(node_t));
    if (!result) {
        perror("malloc");
        return NULL;
    }
    result->data = data;
    result->left = NULL;
    result->right = NULL;
    return result;
}

static node_t *insert(node_t *root, int data) {
    if (!root) return new_node(data);

    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

node_t *build_tree(int *tree_data, size_t tree_data_len) {
    if (tree_data_len == 0) return NULL;
    node_t *root = NULL;

    for (size_t i = 0; i < tree_data_len; i++) {
        root = insert(root, tree_data[i]);
    }

    return root;
}

void free_tree(node_t *tree) {
    if (tree == NULL) return;

    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}

static size_t count_nodes(node_t *tree) {
    if (tree == NULL) return 0;

    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

static void inorder(node_t *tree, int *array, size_t *index) {
    if (tree == NULL) return;

    inorder(tree->left, array, index);
    array[*index] = tree->data;
    (*index)++;
    inorder(tree->right, array, index);
}

int *sorted_data(node_t *tree) {
    size_t len = count_nodes(tree);

    int *array = malloc(len * sizeof(int));
    if (!array) {
        perror("malloc");
        return NULL;
    }

    size_t index = 0;
    inorder(tree, array, &index);

    return array;
}
