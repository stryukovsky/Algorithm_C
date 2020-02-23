//
// Created by dmitry on 23.02.2020.
//

#include "data_type.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct tree_node {
    dtype value;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;


void tree_node_insert(struct tree_node *node, int val) {
    if (node == NULL) {
        node = malloc(sizeof(tree_node));
        node->value = val;
        node->left = NULL;
        node->right = NULL;
    } else {
        if (node->value > val) {
            if (node->right != NULL)
                tree_node_insert(node->right, val);
            else {
                node->right = malloc(sizeof(tree_node));
                node->right->value = val;
                node->right->right = NULL;
                node->right->left = NULL;
            }
        }
        if (node->left != NULL)
            tree_node_insert(node->left, val);
        else {
            node->left = malloc(sizeof(tree_node));
            node->left->value = val;
            node->left->right = NULL;
            node->left->left = NULL;

        }
    }
}


bool tree_node_contains(struct tree_node *node, int val)
{
    tree_node* p = node;
    while(p != NULL)
    {
        if(p->value > val)
        {
            p = p->left;
        }
        if(p->value < val)
        {
            p = p->right;
        } else
            return true;
    }
}