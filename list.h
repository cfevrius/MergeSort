#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct List List;
struct List{
    Node* head;
    Node* tail;
    int size;
};

List* list_create();
List* list_destroy(List* l);

void list_append(List* l, int n);
void list_display(List* l);
void list_reverse(List* l);
void list_sort(List* l);

#endif

