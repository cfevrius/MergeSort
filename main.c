#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

int main(void) {

    int data_to_sort[] = { 2, 5, 3, 4, 1, 6, 0 };
    int node_elements = 7;

    List* l = list_create();
    for(int i = 0; i < node_elements; i++){
        list_append(l, data_to_sort[i]);
    }

    list_display(l);
    list_sort(l);
    list_display(l);

    l = list_destroy(l);
    return 0;
}

