#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int);
void insertOne(Node**, int);
void insertSorted(Node**, int);
void removeOne(Node**);
void printList(Node*);

Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void insertOne(Node** head, int value) {
    Node* node = createNode(value);
    node->next = *head;
    *head = node;
}

void insertSorted(Node** head, int value) {
    if (!(*head)) {
        return insertOne(head, value);
    }

    Node* node = createNode(value);
    Node* aux = *head;
    Node* prev = *head;

    while (*head && value < (*head)->value) {
        prev = *head;
        *head = (*head)->next;
    }

    if (prev == *head) {
        node->next = *head;
        *head = node;
        return;
    }

    prev->next = node;
    node->next = (*head);

    *head = aux;
}

void removeOne(Node** head) {
    if (!(*head)) return;
    Node* aux = *head;
    *head = (*head)->next;
    free(aux);
}

void destroyList(Node** head) {
    Node* aux = NULL;
    while (*head) {
        aux = *head;
        *head = (*head)->next;
        free(aux);
    }
}

void printList(Node* head) {
    while (head) {
        printf("[%d]-> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

int main(int argc, char* argv[]) {
    Node* HEAD = NULL;

    insertSorted(&HEAD, 15);
    insertSorted(&HEAD, 10);
    insertSorted(&HEAD, 5);
    insertSorted(&HEAD, 25);
    insertSorted(&HEAD, 35);

    insertOne(&HEAD, 1);
    insertOne(&HEAD, 2);
    insertOne(&HEAD, 3);
    insertOne(&HEAD, 4);

    printList(HEAD);

    removeOne(&HEAD);
    removeOne(&HEAD);
    removeOne(&HEAD);
    removeOne(&HEAD);

    printList(HEAD);

    destroyList(&HEAD);

    printList(HEAD);
    return 0;
}