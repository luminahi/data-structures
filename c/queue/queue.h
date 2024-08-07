#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct Node {
    const char *name;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Queue {
    struct Node *head;
    struct Node *tail;
    int size;
} Queue;

Node* create_node(const char*);

void enqueue(Queue*, const char*);

void dequeue(Queue*);

void print_queue(Queue);

void destroy_queue(Queue*);

#endif
