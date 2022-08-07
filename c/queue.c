#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    const char *name;
    struct node *next;
    struct node *prev;
} node;

typedef struct ptr {
    struct node *head;
    struct node *tail;
} ptr;

void enqueue(ptr *queue, const char *name) {
    node *no = (node*) malloc(sizeof(node));
    no->name = name;
    no->prev = NULL;
    if (!(queue->tail)) {
        no->next = NULL;
        queue->head = no;
    } else {
        queue->tail->prev = no;
        no->next = queue->tail;
    }
    queue->tail = no;
}

void dequeue(ptr *queue) {
    if (queue->head && !queue->head->prev) {
        free(queue->head);
        queue->head = NULL;
        queue->tail = NULL;
    } else if (queue->head && queue->head->prev) {
        node *temp = queue->head;
        queue->head->prev->next = NULL;
        queue->head = queue->head->prev;
        free(temp);
    }
}

void clearQueue(ptr *queue) {
    while (queue->head) {
        dequeue(queue);
    }
}

void printQueue(node *temp) {
    if (temp && temp->next) {
        while (temp) {
            printf("%s\n", temp->name);
            temp = temp->next; 
        }
    } else if (temp && temp->prev) {
        while (temp) {
            printf("%s\n", temp->name);
            temp = temp->prev;
        }
    }
}

int main(int argc, const char * argv[]) {
    ptr *queue = (ptr*) malloc(sizeof(ptr));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, "c");
    enqueue(queue, "c++");
    enqueue(queue, "rust");
    enqueue(queue, "python3");
    enqueue(queue, "java");
    enqueue(queue, "javascript");

    clearQueue(queue);
    
    printQueue(queue->tail);
    puts("--------");
    printQueue(queue->head);

    printf("%p %p\n", queue->head, queue->tail);

    return 0;
}
