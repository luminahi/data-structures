#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    char name[16];
    struct node *next;
    struct node *prev;
} node;

typedef struct list {
    node *HEAD;
} list;

node *createNode(int id, char *name) {
    node *temp = (node*) malloc(sizeof(node));
    temp->id = id;
    temp->next = NULL;
    temp->prev = NULL;
    strcpy(temp->name, name);
    return temp;
}

void insertNode(list *ptr, node *element) {
    if (!ptr->HEAD) {
        element->next = element;
        element->prev = element;
    } else {
        element->next = ptr->HEAD;
        element->prev = ptr->HEAD->prev;
        element->prev->next = element;
        element->next->prev = element;
    }
    ptr->HEAD = element;
}

int removeNode(list *ptr, int id) {
    if (ptr->HEAD) {
        node *temp = ptr->HEAD;
        do {
            if (temp->id == id) {
                if (temp == temp->next) {
                    ptr->HEAD = NULL;
                } else {
                    ptr->HEAD = temp == ptr->HEAD ? temp->next: ptr->HEAD;
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                }
                free(temp);
                return 1;
            }
            temp = temp->next;
        } while (temp != ptr->HEAD);
    }
}

void printList(list *ptr) {
    if (ptr->HEAD) {
        node *temp = ptr->HEAD;
        do {
            printf("ID: %d - Name: %s\n", temp->id, temp->name);
            temp = temp->next;
        } while (temp != ptr->HEAD);
    }
}

void clearList(list *ptr) {
    if (ptr->HEAD) {
        node *temp = ptr->HEAD;
        node *hold = NULL;
        do {
            hold = temp;
            temp = temp->next;
            free(hold);
        } while (temp != ptr->HEAD);
        ptr->HEAD = NULL;
    }
}

int main(int argc, const char *argv) {
    list *ptr = (list*) malloc(sizeof(list));
    ptr->HEAD = NULL;

    insertNode(ptr, createNode(0, "mongodb"));
    insertNode(ptr, createNode(1, "mariadb"));
    insertNode(ptr, createNode(2, "mysql"));
    insertNode(ptr, createNode(3, "apache"));
    insertNode(ptr, createNode(4, "docker"));
    insertNode(ptr, createNode(5, "podman"));
    printList(ptr);
    removeNode(ptr, 3);
    removeNode(ptr, 10);
    clearList(ptr);
    return 0;
}
