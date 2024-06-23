#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <data.h>
#include <crypt.h>

#define TABLE_SIZE 8

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

/**
 * Allocate memory to a new node and set key and text with the provided values.
 * 
 * @return A pointer to a new Node.
 */
Node* createNode(char*, char*);

/**
 * Insert a new Node in the hash table in a calculated index, each Node is added
 * in the start of the linked list.
 */
void insertNode(HashTable*, char*, char*);

/**
 * Iterate through a buffer and get lines of 32 bytes and store in the provided 
 * hash table, the first 3 bytes are used as a key for each inserted line.
 * 
 * @param hashTable the hash table to populate.
 * @param buffer Each line of the buffer should have at most 32 bytes.
 */
void processData(HashTable*, char*);

void printList(Node*);

/**
 * Iterate through all elements in each linked list in the hash table and 
 * print in stdout.
 * 
 * @param hashTable The hash table to be printed.
 */
void printTable(HashTable*);

/**
 * Initialize a new hash table and set all pointers in the list to NULL,
 * each element of the list use a simply linked list.
 * 
 * @return A pointer to a new hash table.
 */
HashTable* createTable();

/**
 * Free all resources from the provided hash table and set all 
 * pointers in the list to NULL.
 * 
 * @param hashTable A hash table created with createTable.
 */
void destroyTable(HashTable**);

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
    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
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
    if (!hashTable) return;
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index: [%d]\n", i);
        printList(hashTable->list[i]);
    }
}

void processData(HashTable* hashTable, char* buffer) {
    char* key = (char*) malloc(sizeof(char) * 4);
    int i = 0, j = 0;
    key[3] = '\0'; 
    char* line = (char*) malloc(sizeof(char) * 32);
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

void destroyTable(HashTable** hashTable) {
    if (!(*hashTable)) return;
    Node* temp = NULL;
    Node* aux = NULL;
    for (int i = 0; i < TABLE_SIZE; i++) {
        temp = (*hashTable)->list[i];
        while (temp) {
            aux = temp;
            temp = temp->next;
            free(aux);
        }
        (*hashTable)->list[i] = NULL;
    }

    free(*hashTable);
    (*hashTable) = NULL;
}

int main(int argc, char* argv[]) {
    HashTable* hashTable = createTable();
    
    char* buffer = readDataFromFile("data.txt");
    processData(hashTable, buffer);
    free(buffer);

    printTable(hashTable);

    destroyTable(&hashTable);
    
    return 0;
}