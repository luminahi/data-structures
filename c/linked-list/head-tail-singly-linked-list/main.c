#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct List {
    struct Node* HEAD;
    struct Node* TAIL;
    int size;
} List;

Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void insertAtStart(List* list, int value) {
    Node* node = createNode(value);

    node->next = list->HEAD;
    list->HEAD = node;

    if (list->size == 0) {
        list->TAIL = list->HEAD;
    }

    list->size++;
}

void insertAtEnd(List* list, int value) {
    Node* node = createNode(value);

    if (list->size == 0) {
        return insertAtStart(list, value);
    }

    list->TAIL->next = node;
    list->TAIL = node;

    list->size++;
}

void printList(List list) {
    printf("[HEAD] ");
    for (int i = 0; i < list.size; i++) {
        printf("[%d] ", list.HEAD->value);
        list.HEAD = list.HEAD->next;
    }
    printf("[TAIL]\n");
}

void removeAtStart(List* list) {
    if (list->size == 0) return;
    
    Node* aux = list->HEAD;
    list->HEAD = list->HEAD->next;
    list->size--;
    free(aux);
}

void removeAtEnd(List* list) {
    if (list->size == 0) return;
    if (list->size == 1) return removeAtStart(list);

    Node* aux = list->HEAD;

    while (aux->next != list->TAIL) {
        aux = aux->next;
    }

    free(list->TAIL);
    list->TAIL = aux;
    list->size--;
}

void printListInfo(List list) {
    if (list.size == 0) {
        printf("[HEAD: NULL] :::: [TAIL: NULL] @Size: %d\n", list.size);
        return;
    }
    printf("[HEAD: %d] :::: [TAIL: %d] @Size: %d\n", 
        list.HEAD->value,
        list.TAIL->value,
        list.size);
}

int main(int argc, char* argv[]) {
    List list = { .HEAD = NULL, .TAIL = NULL, .size = 0 };

    printListInfo(list);
    printList(list);

    insertAtStart(&list, 10);
    insertAtEnd(&list, 1000);
    insertAtStart(&list, 20);

    printListInfo(list);
    printList(list);

    insertAtStart(&list, 30);
    insertAtEnd(&list, 500);
    insertAtStart(&list, 40);
    insertAtEnd(&list, 250);

    printListInfo(list);
    printList(list);

    removeAtEnd(&list);
    removeAtEnd(&list);
    removeAtEnd(&list);
    removeAtEnd(&list);
    removeAtEnd(&list);
    removeAtEnd(&list);
    removeAtEnd(&list);
    removeAtEnd(&list);

    printListInfo(list);
    printList(list);
    return 0;
}