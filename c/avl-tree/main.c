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

int height(AVLNode* node) {
    if (node == NULL) return 0;
    return node->height;
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
       
    // y->height = MAX(height(y->left), height(y->right)) + 1;
    // x->height = MAX(height(x->left), height(x->right)) + 1;

    return x;
}

int main(int argc, char* argv[]) {
    const int result = MAX(20, 40);
    printf("%d\n", result);
    return 0;
}
