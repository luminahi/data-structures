#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    struct node *next;
} node;

node * createNode(node **head, char *name) {
    node *no = (node*) malloc(sizeof(node));
    no->name = name;
    no->next = *head;
    *head = no;
}

int insertNode(node **head, char *name) {
    node *parent = *head;
    node *current = *head;
    while (current) {
        if (!strcmp(name, current->name)) {
            if (parent == current) {
                *head = current->next;
            } else {
                parent->next = current->next;
            }
            free(current);
            return 1;
        } else {
            parent = current;
            current = current->next;
        }
    }
    return 0;
}

void clearList(node **head) {
    node *temp = NULL;
    while (*head) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void printList(node *head) {
    if (head) {
        putchar('[');
        while (head) {
            printf("%s, ", head->name);
            head = head->next;
        }
        puts("\b\b]");
    }
}

int main() {
    node *head = NULL;
    createNode(&head, "c++");
    createNode(&head, "rust");
    createNode(&head, "c");
    createNode(&head, "python3");
    createNode(&head, "javascript");
    printList(head);
    clearList(&head);
    return 0;
}
