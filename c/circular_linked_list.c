#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int value;
    char name[16];
    struct node *next;
} node;

typedef struct list {
    node *HEAD;
} list;

node *createNode(int value, char *name) {
    node *temp = (node*) malloc(sizeof(node));
    temp->value = value;
    strcpy(temp->name, name);
    return temp;
}

void insertNode(list *ptr, node *element) {
    /**
     * primeiro elemento a ser inserido na lista
     **/
    if (!ptr->HEAD) {
        ptr->HEAD = element;
        ptr->HEAD->next = ptr->HEAD;
    } else {
        element->next = ptr->HEAD->next;
        ptr->HEAD->next = element;
    }
}

void printNodes(list *ptr) {
    if (ptr->HEAD) {
        node *temp = ptr->HEAD->next;
        while (temp != ptr->HEAD) {
            printf("%s\n", temp->name);
            temp = temp->next;
        }
        printf("%s\n", temp->name);
    }
}

void clearList(list *ptr) {
    if (ptr->HEAD) {
        node *iterator = ptr->HEAD->next;
        node *temp = NULL;
        while (iterator != ptr->HEAD) {
            temp = iterator;
            iterator = iterator->next;
            temp->next = NULL;
            free(temp);
        }
        free(iterator);
        ptr->HEAD = NULL;
    }
}

int main(int argc, const char * argv[]) {
    list *listPtr = (list*) malloc(sizeof(list));
    listPtr->HEAD = NULL;
    
    insertNode(listPtr, createNode(10, "javascript"));
    insertNode(listPtr, createNode(20, "typescript"));
    insertNode(listPtr, createNode(30, "ruby"));
    insertNode(listPtr, createNode(40, "perl"));
    insertNode(listPtr, createNode(55, "python"));

    clearList(listPtr);
    printNodes(listPtr);

    free(listPtr);

    return 0;
}
