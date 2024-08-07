#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

Node* create_node(const char* name) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->name = name;
    node->prev = NULL;
    node->next = NULL;
}

void enqueue(Queue *queue, const char* name) {
    Node* node = create_node(name);
    
    if (queue->size == 0) {
        queue->head = node;
    } else {
        queue->tail->prev = node;
        node->next = queue->tail;
    }

    queue->tail = node;
    queue->size++;
}

void dequeue(Queue* queue) {
    if (queue->size <= 0) return;
    Node* temp = queue->head;

    if (queue->size == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head->prev->next = NULL;
        queue->head = queue->head->prev;
    }
    
    queue->size--;
    free(temp);
}

void destroy_queue(Queue* queue) {
    while (queue->head) {
        dequeue(queue);
    }
}

void print_queue(Queue queue) {
    Node* temp = queue.tail;
    
    while (temp) {
        printf("%s\n", temp->name);
        temp = temp->next; 
    }
}
