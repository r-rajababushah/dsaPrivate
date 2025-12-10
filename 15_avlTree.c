#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalanceFactor(struct Node *N) {
    if (N == NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rotateRight(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct Node *rotateLeft(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    
    if (key > root->key)
        return search(root->right, key);

    return search(root->left, key);
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d(h=%d,b=%d) ", root->key, root->height, getBalanceFactor(root));
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    int keys_to_insert[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(keys_to_insert) / sizeof(keys_to_insert[0]);
    int i;

    printf("1. Insertion (Demonstrating Balancing):\n");
    for (i = 0; i < n; i++) {
        root = insert(root, keys_to_insert[i]);
        printf("   Inserted %d. Inorder: ", keys_to_insert[i]);
        inorderTraversal(root);
        printf("\n");
    }
    
    printf("\nFinal AVL Tree Inorder Traversal (Key(Height,Balance)): ");
    inorderTraversal(root); 

    struct Node* minNode = findMin(root);
    printf("\n\n2. Finding Min and Max:\n");
    printf("   Minimum value in the tree: %d\n", (minNode != NULL) ? minNode->key : -1);
    struct Node* maxNode = findMax(root);
    printf("   Maximum value in the tree: %d\n", (maxNode != NULL) ? maxNode->key : -1);

    printf("\n3. Searching for keys:\n");
    int search_key_present = 40;
    int search_key_absent = 100;
    
    struct Node* result_present = search(root, search_key_present);
    printf("   Search for %d: %s\n", search_key_present, (result_present != NULL) ? "Found" : "Not Found");

    struct Node* result_absent = search(root, search_key_absent);
    printf("   Search for %d: %s\n", search_key_absent, (result_absent != NULL) ? "Found" : "Not Found");

    printf("\n4. Deletion Operation (Deleting 40)...\n");
    root = deleteNode(root, 40);
    printf("      Inorder Traversal after deleting 40: ");
    inorderTraversal(root); 
    
    printf("\n   Deletion Operation (Deleting 30 - two children)...\n");
    root = deleteNode(root, 30);
    printf("      Inorder Traversal after deleting 30: ");
    inorderTraversal(root); 
    
    printf("\n");

    return 0;
}