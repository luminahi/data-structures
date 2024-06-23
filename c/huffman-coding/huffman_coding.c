#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char code;
    int weight;
    struct node *next;
    struct node *prev;
    struct node *left;
    struct node *right;
} node;

typedef struct queue {
    node *HEAD;
    node *TAIL;
} queue;

typedef struct tree {
    node *ROOT;
} tree;

node * createNode(char code, int weight) {
    node *temp = (node*) malloc(sizeof(node));
    temp->code = code;
    temp->weight = weight;
    temp->next = NULL;
    temp->prev = NULL;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int enqueueWithPriority(queue *ptr, node *temp) {
    if (!ptr->HEAD) {
        temp->next = NULL;
        ptr->HEAD = temp;
        ptr->TAIL = temp;
        return 1;
    } else {
        node *aux = ptr->TAIL;
        node *parent = aux;
        while (aux) {
            if (temp->weight > aux->weight) {
                temp->prev = aux->prev;
                if (!aux->prev) {
                    ptr->TAIL = temp;
                } else {
                    aux->prev->next = temp;
                }
                aux->prev = temp;
                temp->next = aux;
                return 1;
            }
            parent = aux;
            aux = aux->next;
        }
        parent->next = temp;
        temp->prev = parent;
        temp->next = NULL;
        ptr->HEAD = temp;
        return 1;
    }
}

node * dequeue(queue *ptr) {
    node *temp = ptr->HEAD;
    if (temp && temp->prev) {
        ptr->HEAD = ptr->HEAD->prev;
        ptr->HEAD->next = NULL;
    } else if (temp) {
        ptr->HEAD = NULL;
        ptr->TAIL = NULL;
    }
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void printQueue(queue *ptr) {
    node *temp = ptr->TAIL;
    printf("=TAIL=\n");
    while (temp) {
        printf("%c %d\n", temp->code, temp->weight);
        temp = temp->next;
    }
    printf("=HEAD=\n");
}

int charCounter(char c, char *string) {
    int i = 0;
    int counter = 0;
    while (string[i] != '\0') {
        if (c == string[i]) {
            counter++;
            string[i] = '*';
        }
        i++;
    }
    return counter;
}

void buildQueue(queue *ptr, char *filename) {
    FILE *file = fopen(filename, "r");
    node *temp = NULL;
    int i = 0;
    int counter = 0;
    char c = '\0';
    char string[255];
    fgets(string, 255, file);
    while (string[i]) {
        if (string[i] != '*' && string[i] != '\n') {
            c = string[i];
            counter = charCounter(string[i], string);
            temp = createNode(c, counter);
            enqueueWithPriority(ptr, temp);
        }
        i++;
    }
    fclose(file);
}

void printTree(node *root) {
    if (root) {
        printTree(root->left);
        printf("Tree-> Code: %c Weight: %d\n", 
            root->code, root->weight);
        printTree(root->right);
    }
}

int isLeaf(node *root) {
    return !(root->left) && !(root->right);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void createBcode(node *root, int arr[], int  n) {
    if (root->left) {
        arr[n] = 0;
        createBcode(root->left, arr, n + 1);
    }
    if (root->right) {
        arr[n] = 1;
        createBcode(root->right, arr, n + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->code);
        printArray(arr, n);
    }
}

int buildTree(queue *ptr, tree *tnode) {
    node *temp1 = NULL;
    node *temp2 = NULL;
    node *parent = NULL;
    while (1) {
        if (ptr->HEAD && ptr->HEAD->prev) {

            temp1 = dequeue(ptr);
            temp2 = dequeue(ptr);
            parent = (node*) malloc(sizeof(node));
            parent->weight = temp1->weight + temp2->weight;
            parent->code = '*';
            parent->left = temp1;
            parent->right = temp2;
            parent->next = NULL;
            parent->prev = NULL;
            enqueueWithPriority(ptr, parent);
            
        } else if (ptr->HEAD) {
            tnode->ROOT = dequeue(ptr);
            return 1;
        }
    }
}

void clearTree(node *root) {
    if (root) {
        clearTree(root->left);
        clearTree(root->right);
        free(root);
    }
}

void huffmanCoding() {
    queue *queuePtr = (queue*) malloc(sizeof(queue));
    tree *treePtr = (tree*) malloc(sizeof(tree));
    
    queuePtr->HEAD = NULL;
    queuePtr->TAIL = NULL;
    treePtr->ROOT = NULL;

    buildQueue(queuePtr, "alfabeto.txt");
    buildTree(queuePtr, treePtr);
    int arr[10];
    createBcode(treePtr->ROOT, arr, 0);
    printTree(treePtr->ROOT);
    clearTree(treePtr->ROOT);
    
    free(treePtr);
    free(queuePtr);
}

int main(int argc, const char * argv[]) {
    huffmanCoding();
    return 0;
}