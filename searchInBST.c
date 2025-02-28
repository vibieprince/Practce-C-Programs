#include <stdio.h>
#include <stdlib.h>

// Structure for a node in BST
struct Node {
    int key;
    struct Node* left, *right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Iterative function to search a key in BST
struct Node* search(struct Node* root, int key) {
    while (root != NULL) {
        if (key == root->key)  // Key found
            return root;
        else if (key < root->key)  // Search in left subtree
            root = root->left;
        else  // Search in right subtree
            root = root->right;
    }
    return NULL;  // Key not found
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int key) {
    struct Node* newNode = createNode(key);
    if (root == NULL)
        return newNode;

    struct Node* parent = NULL, *current = root;

    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Driver function
int main() {
    struct Node* root = NULL;

    // Inserting nodes into BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key = 40;
    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Key %d found in BST.\n", key);
    else
        printf("Key %d not found in BST.\n", key);

    return 0;
}
