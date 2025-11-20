#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key > root->key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* findMax(struct Node* node) {
    struct Node* current = node;
    
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int keys_to_insert[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(keys_to_insert) / sizeof(keys_to_insert[0]);
    int i;

    printf("1. Inserting keys: ");
    for (i = 0; i < n; i++) {
        printf("%d ", keys_to_insert[i]);
        root = insert(root, keys_to_insert[i]);
    }
    
    printf("\n   Inorder Traversal (Sorted order): ");
    inorderTraversal(root); 

    printf("\n\n2. Searching for keys:\n");
    int search_key_present = 40;
    int search_key_absent = 90;
    
    struct Node* result_present = search(root, search_key_present);
    printf("   Search for %d: %s\n", search_key_present, (result_present != NULL) ? "Found" : "Not Found");

    struct Node* result_absent = search(root, search_key_absent);
    printf("   Search for %d: %s\n", search_key_absent, (result_absent != NULL) ? "Found" : "Not Found");

    printf("\n3. Finding Min and Max:\n");
    struct Node* minNode = findMin(root);
    printf("   Minimum value in the tree: %d\n", (minNode != NULL) ? minNode->key : -1);
    struct Node* maxNode = findMax(root);
    printf("   Maximum value in the tree: %d\n", (maxNode != NULL) ? maxNode->key : -1);

    printf("\n4. Deletion Operation:\n");
    
    printf("   Deleting 20 (Leaf node)...\n");
    root = deleteNode(root, 20);
    printf("      Inorder Traversal after deleting 20: ");
    inorderTraversal(root);

    printf("\n   Deleting 70 (Node with one child)...\n");
    root = deleteNode(root, 70);
    printf("      Inorder Traversal after deleting 70: ");
    inorderTraversal(root);

    printf("\n   Deleting 50 (Node with two children - Root)...\n");
    root = deleteNode(root, 50);
    printf("      Inorder Traversal after deleting 50: ");
    inorderTraversal(root); 
    printf("\n      New Root Key (Should be 60): %d\n", root->key);

    return 0;
}