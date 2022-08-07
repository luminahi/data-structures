#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#define HASH_SIZE 20

typedef struct node {
    char * key;
    unsigned int value;
    struct node *next;
} node;

typedef struct hash {
    struct node * list[HASH_SIZE];
} hash;

unsigned long hashcode(char * key) {
    unsigned long hashc = 2825;
    unsigned int c;
    while ( c = *key++) {
        hashc = ((hashc << 5) + hashc ) + c;
    }
    return hashc % HASH_SIZE;
}

node * createNode(char * key, unsigned int value) {
    node * new = (node*) malloc(sizeof(node));
    new->key = key;
    new->value = value;
    return new;
}

void insertNode(hash *table, char *key, unsigned int value) {
    unsigned int index = hashcode(key);
    node *no = createNode(key, value);
    if (!no) {
        table->list[index] = no;
        no->next = NULL;
    } else {
        no->next = table->list[index];
        table->list[index] = no;
    }
}

void print(hash *table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("- [%d] - Address: %p \n", i, table->list[i]);
        node * start = table->list[i]; 
        while (table->list[i]) {
            printf("%s\n", table->list[i]->key);
            table->list[i] = table->list[i]->next;
        }
        table->list[i] = start;
    }
}

node * search(hash *table, char * key) {
    unsigned int index = hashcode(key);
    node * start = table->list[index];
    while (table->list[index]) {
        if (!strcmp(table->list[index]->key, key)) {
            node * search = table->list[index];
            table->list[index] = start;
            return search;
        }
        table->list[index] = table->list[index]->next;
    }
    table->list[index] = start;
    return NULL;
}

int main() {
    hash * table = (hash*) malloc(sizeof(hash));
    insertNode(table, "alex", 0);
    insertNode(table, "sara", 1);
    insertNode(table, "linux", 2);
    insertNode(table, "windows", 3);
    insertNode(table, "ubuntu", 4);
    insertNode(table, "bruna", 5);
    insertNode(table, "isabeau", 6);
    insertNode(table, "natal", 7);
    insertNode(table, "ki", 8);
    insertNode(table, "no", 9);
    insertNode(table, "ue", 10);
    insertNode(table, "vista", 11);
    print(table);
    printf("-------------------------------\n");
    node * search1 = search(table, "sara");
    node * search2 = search(table, "ubuntu");
    node * search3 = search(table, "vista");
    printf("Chave: %s Valor: %d\n", search1->key, search1->value);
    printf("Chave: %s Valor: %d\n", search2->key, search2->value);
    printf("Chave: %s Valor: %d\n", search3->key, search3->value);
    return 0;
}
