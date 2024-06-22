#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <data.h>

#define TABLE_SIZE 16

typedef struct Node {
    char key[4];
    char text[32];
    struct Node* next;
} Node;

typedef struct HashTable {
    struct Node* list[TABLE_SIZE];
} HashTable;

unsigned int hashIndex(char*);
unsigned long hash(char*);
Node* createNode(char*, char*);
void insertNode(HashTable*, char*, char*);
void printList(Node*);
void printTable(HashTable*);

Node* createNode(char* key, char* text) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->key, key);
    strcpy(node->text, text);
    return node;
}

void insertNode(HashTable* hashTable, char* key, char* text) {
    Node* node = createNode(key, text);
    int index = hashIndex(key);
    node->next = hashTable->list[index];
    hashTable->list[index] = node;
}

unsigned long hash(char* string) {
    unsigned long hash = 5381;
    int c;

    while ((c = *(string++))) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

unsigned int hashIndex(char* string) {
    return hash(string) % TABLE_SIZE;
}

HashTable* createTable() {
    HashTable * hashTable = (HashTable*) malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->list[i] = NULL;
    }

    return hashTable;
}

void printList(Node* node) {
    Node* temp = node;
    while (temp) {
        printf("Key: %s :::: Value: %s\n", temp->key, temp->text);
        temp = temp->next;
    }
}

void printTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index: [%d]\n", i);
        printList(hashTable->list[i]);
    }
}

void processData(HashTable *hashTable, char *buffer) {
    char *key = (char*) malloc(sizeof(char) * 4);
    int i = 0, j = 0;
    key[3] = '\0'; 
    char *line = (char*) malloc(sizeof(char) * 32);
    while (buffer[i] != '\0') {
        while (buffer[i] != '\n') {
            line[j] = buffer[i];
            j++;
            i++;
        }
        line[j] = '\0';
        j = 0;
        i++;
        strncpy(key, line, 3);
        insertNode(hashTable, key, line);
    }
    
    free(key);
    free(line);
}

int main(int argc, char* argv[]) {
    HashTable* hashTable = createTable();
    
    char *buffer = readDataFromFile("data.txt");
    processData(hashTable, buffer);

    free(buffer);
    printTable(hashTable);
    
    return 0;
}