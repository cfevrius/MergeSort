#ifndef LIST_C
#define LIST_C

#include "list.h"

#include <stdio.h>
#include <stdlib.h>

List* list_create(){
    List* l = (List*)calloc(1, sizeof(List));
    return l;
}

void list_destroy(List* l){
    Node* curr = l->head;
    while(curr){
        Node* temp = curr;
        curr = curr->next;
        node_destroy(temp);
    }
    free(l);
}

void list_append(List* l, int n){
    Node* new_node = node_create(n);
    new_node->next = NULL;
    if(l->head == NULL){
        l->head = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node;     
    }
    (l->size)++;
}

void list_display(List* l){
    printf("[");
    for(Node* curr = l->head; curr; curr=curr->next){
        if(curr->next){
            printf("%d, ", curr->data);
        } else {
            printf("%d", curr->data);
        }
    }
    printf("]\n");
}

Node* node_reverse(Node* curr, Node* prev){
    /* Base Case */
    if(curr->next == NULL){
        curr->next = prev;
        return curr;
    /* Recursive Call */
    } else {
        Node* head = node_reverse(curr->next, curr);
        curr->next = prev;
        return head;
    }
}

void list_reverse(List* l){
    l->tail = l->head;
    l->head = node_reverse(l->head, NULL);
}

void list_split(Node* head, Node** left, Node** right){
    Node *fast_pointer, *slow_pointer;
    fast_pointer = slow_pointer = head;

    /* Based on algorithm derived from: 
     * https://www.quora.com/What-is-a-slow-pointer-and-a-fast-pointer-in-a-linked-list
     */
    while(slow_pointer && fast_pointer && fast_pointer->next) {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;  
    }

    Node* curr = head;
    if(curr != slow_pointer){
        while(curr &&  curr->next != slow_pointer){
            curr = curr->next;
        }
        curr->next = NULL;
    }

    *left = head;
    *right = slow_pointer;
}

Node* list_merge(Node* left, Node* right){
    Node *curr_left, *curr_right;
    Node* head = (left->data < right->data) ? left : right;

    curr_left  = left;
    curr_right = right;

    while(curr_left != NULL && curr_right != NULL){
        Node* original_left_next = curr_left->next;
        Node* original_right_next = curr_right->next;
        if(curr_left->data < curr_right->data){
            if(original_left_next){
                if(curr_right->data <= curr_left->next->data){
                    curr_left->next = curr_right;
                }
                curr_left = original_left_next;
            } else {
                curr_left->next = curr_right;
                curr_left = NULL;
            }
        }  else {
            if(original_right_next){
                if(curr_left->data <= curr_right->next->data){
                    curr_right->next = curr_left;
                }
                curr_right = original_right_next;
            } else {
                curr_right->next = curr_left;
                curr_right = NULL;
            }
        } 
    }
    return head;
}

Node* list_merge_sort(Node* head){
    /* Base Case */
    if(!head->next){
        return head;
    /* Recursive Call */
    } else {
        Node *left = NULL;
        Node *right = NULL;
        list_split(head, &left, &right);

        left = list_merge_sort(left);
        right = list_merge_sort(right);

        Node* head = list_merge(left, right);
        return head;
    }
}

void list_sort(List* l){
    l->head = list_merge_sort(l->head);
}

#endif

