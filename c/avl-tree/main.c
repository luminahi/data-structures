#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(x, y) ((x >= y) ? x : y);

typedef struct AVLNode {
    int value;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

AVLNode* createNode(int);
int height(AVLNode*);
int getBalance(AVLNode*);

int height(AVLNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(AVLNode* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

AVLNode* insert(AVLNode* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + MAX(height(node->left), height(node->right));

    return node;
}

AVLNode* createNode(int value) {
    AVLNode* node = (AVLNode*) malloc(sizeof(AVLNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;
       
    y->height = MAX(height(y->left), height(y->right)) + 1;
    x->height = MAX(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = MAX(height(x->left), height(x->right)) + 1;
    y->height = MAX(height(y->left), height(y->right)) + 1;
    
    return y;
}

void printTree(AVLNode* node) {
    if (node) {
        printf("Value: %d \nHeight: %d\n\n", node->value, node->height);
        
        printTree(node->left);
        printTree(node->right);
    }
}

int main(int argc, char* argv[]) {
    AVLNode* root = NULL;

    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 0);
    root = insert(root, -5);

    printTree(root);
    return 0;
}
