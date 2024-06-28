#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct node node;

struct node {
    uint16_t id;
    char *op;
    node *next;
};

node * push(node *top, uint16_t id, char *op);
node * pop(node *top);

node * push(node *top, uint16_t id, char *op) {
    node * no = (node*) malloc(sizeof(node));
    no->id = id;
    no->op = op;
    no->next = top;
    return no;
}

node * pop(node *top) {
    if (top) {
        node *no = top->next;
        free(top);
        return no;
    }
    printf("Empty Stack\n");
    return top;
}

void print(node *top) {
    while(top) {
        printf("| %d - %s |\n", top->id, top->op);
        top = top->next;
    }
    printf("------------\n");
}

int main() {
    node *top = NULL;
    print(top);
    top = push(top, 1, "clea");
    top = push(top, 2, "line");
    top = push(top, 3, "boxe");
    print(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = push(top, 4, "cois");
    top = push(top, 5, "alex");
    top = push(top, 6, "bebe");
    top = push(top, 7, "brbe");

    print(top);
    return 0;
}
