#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    unsigned long value;
    struct node *left;
    struct node *right;
} node;

int max(int x, int y) {
    return x > y ? x : y;
}

void showFullTree(node **root) {
    if (*root) {
        showFullTree(&(*root)->left);
        printf("%lu\n", (*root)->value);
        showFullTree(&(*root)->right);
    }
}

void showLeftTree(node **root) {
    if (*root) {
        printf("%lu\n", (*root)->value);
        showLeftTree(&(*root)->left);
    }
}

void showRightTree(node **root) {
    if (*root) {
        printf("%lu\n", (*root)->value);
        showRightTree(&(*root)->right);
    }
}

void insertNodeRec(node **root, unsigned long value) {
    if ((*root) && value < (*root)->value) {
        insertNodeRec(&(*root)->left, value);
    } else if ((*root) && value > (*root)->value) {
        insertNodeRec(&(*root)->right, value);
    } else {
        node * no = (node*) malloc(sizeof(node));
        no->value = value;
        *root = no;
    }
}

int insertNode(node **root, unsigned long value) {
    node *temp = (node*) malloc(sizeof(node));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;

    if (!(*root)) {
        *root = temp;
    } else {
        node *current = *root;
        node *parent;
        while (true) {
            parent = current;
            if (value < current->value) {
                current = current->left;
                if (!current) {
                    parent->left = temp;
                    return -1;
                }
            } else {
                current = current->right;
                if (!current) {
                    parent->right = temp;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int treeHeight(node *root) {
    if (root) {
        return max(treeHeight(root->left), treeHeight(root->right)) + 1;
    } else return -1;
}

int nodeCounter(node **root) {
    if (*root) {
        return (nodeCounter(&(*root)->left) + nodeCounter(&(*root)->right) + 1);
    } else return 0;
}

void searchTreeRec(node **root, unsigned long value) {
    if (*root) {
        printf("%lu\n", (*root)->value);
        if (value < (*root)->value) {
            searchTreeRec(&(*root)->left, value);
        } else {
            searchTreeRec(&(*root)->right, value);
        }
    }
}

node * searchTree(node **root, unsigned long value) {
    node *temp = *root;
    while (temp) {
        if (value == temp->value) {
            return temp;
        } else if (value < temp->value) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return 0;
}

node * rightSubTree(node *root) {
    node *parent = root;
    while (root->right) {
        parent = root;
        root = root->right;
    }
    return parent;
}

int removeNode(node **root, unsigned long value) {
    node *current = *root;
    node *parent = *root;
    while (current) {
        if (value == current->value) {
            if (current->left && current->right) { /* elemento a ser deletado tem 2 filhos */
                node *temp = rightSubTree(current->left);
                if (temp->right) {
                    current->value = temp->right->value;
                    free(temp->right);
                    temp->right = NULL;
                } else {
                    current->value = temp->value;
                    current->left = temp->left;
                    free(temp);
                }
            } else {
                if (parent->left == current) { /* elemento a ser deletado tem um ou nenhum filho */
                    parent->left = current->left ? current->left : current->right;
                } else {
                    parent->right = current->right ? current->right : current->left;
                }
                free(current);
            }
            return 1;
        } else if (value < current->value) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }
    return 0;
}

void clearTree(node **root) {
    if (*root) {
        clearTree(&(*root)->left);
        clearTree(&(*root)->right);
        free(*root);
        *root = NULL;
    }
}

int main() {
    node *root = NULL;
    int lista[] = {500, 250, 750, 125, 350, 650, 
    1000, 50, 200, 280, 450, 550, 680, 800, 1100};

    for (int i = 0; i < sizeof(lista)/4; i++) {
        insertNode(&root, lista[i]);
    }
    showFullTree(&root);
    clearTree(&root);
    showFullTree(&root);
    return 0;
}
