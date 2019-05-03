#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

int main(void) {

    List* l = list_create();

    list_append(l, 2);
    list_append(l, 5);
    list_append(l, 3); 
    list_append(l, 4);
    list_append(l, 1);
    list_append(l, 6);     
    list_append(l, 0);

    list_display(l);
    list_sort(l);
    list_display(l);

    l = list_destroy(l);
    return 0;
}

