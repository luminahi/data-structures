#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

Node* create_node(char* value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void insert_one(LinkedList* list, char* value) {
    Node* node = create_node(value);
    node->next = list->HEAD;
    list->HEAD = node;
    list->length++;
}

Node* remove_one(LinkedList* list, char* value) {
    if (!value || list->length < 1) return NULL;

    Node* previous = NULL;
    Node* current = list->HEAD;

    while (current) {
        if (strcmp(current->value, value) == 0) {
            Node* aux = current;
            if (previous) previous->next = current->next;
            else list->HEAD = list->HEAD->next;
            list->length--;

            return aux;
        }

        previous = current;
        current = current->next;
    }

    return NULL;
}

void destroy_list(LinkedList* list) {
    Node* aux = NULL;

    while (list->HEAD) {
        aux = list->HEAD;
        list->HEAD = list->HEAD->next;
        free(aux);
        list->length = 0;
    }
}

void print_list(LinkedList* list) {
    Node* aux = list->HEAD;
    
    while (aux) {
        printf("[%s]-> ", aux->value);
        aux = aux->next;
    }
    printf("NULL\n");
}

LinkedList* init_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->HEAD = NULL;
    list->length = 0;

    return list;
}

