#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct Node {
    char* value;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* HEAD;
    int length;
} LinkedList;

Node* create_node(char* value);

void insert_one(LinkedList* list, char* value);

Node* remove_one(LinkedList* list, char* value);

void print_list(LinkedList* list);

void destroy_list(LinkedList* list);


#endif
