#include "stdio.h"
#include "stdlib.h"

//Node Definition
typedef struct node {
    int key;
    struct node *left, *right;
} BST;

//Create new node
BST *newNode(int key) {
    BST *temp = (BST *) malloc(sizeof(BST));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

//Insert new node
BST *insertNode(BST *root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left = insertNode(root->left, key);
    if (key > root->key)
        root->right = insertNode(root->right, key);
    return root;
}

//Delete node
BST *deleteNode(BST *root, int key) {
    BST *current;
    if (root == NULL) {
        return root;
    } else if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            BST *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BST *temp = root->left;
            free(root);
            return temp;
        }
        current = root->right;
        while (current->left != NULL) {
            current = current->left;
        }
        root->key = current->key;
        root->right = deleteNode(root->right, current->key);
    }
    return root;
}

//In Order traversal
void inOrderTraversal(BST *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

//Post Order traversal
void postOrderTraversal(BST *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->key);
    }
}

//Pre Order traversal
void preOrderTraversal(BST *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    BST *root = NULL;
    root = insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 50);
    insertNode(root, 5);
    insertNode(root, 90);
    insertNode(root, 25);
    insertNode(root, 40);
    printf("In Order Traversal\n");
    inOrderTraversal(root);
    printf("\n\nPre Order Traversal\n");
    preOrderTraversal(root);
    printf("\n\nPost Order Traversal\n");
    postOrderTraversal(root);
    deleteNode(root, 25);
    printf("\n\nIn Order Traversal(25 delete)\n");
    inOrderTraversal(root);
    deleteNode(root, 90);
    printf("\n\nPost Order Traversal(90 delete)\n");
    postOrderTraversal(root);
}