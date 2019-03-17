#ifndef NODE_C
#define NODE_C

#include "node.h"

#include <stdlib.h>

Node* node_create(int n){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->data = n;
    return node;
}

void node_destroy(Node* n){
    free(n);
}

#endif 
