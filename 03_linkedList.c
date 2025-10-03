#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void traverseList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfterNode(struct Node *prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The previous node cannot be NULL.\n");
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertAtEnd(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void insertAtPosition(struct Node **head_ref, int new_data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head_ref, new_data);
        return;
    }

    struct Node *current = *head_ref;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position is out of bounds.\n");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = current->next;
    current->next = new_node;
}

void freeList(struct Node *head) {
    struct Node *current = head;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node *head = NULL;

    printf("1. Initial list:\n");
    traverseList(head);
    printf("\n");

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 30);
    printf("2. After inserting 10 and 30 at end:\n");
    traverseList(head);

    insertAtBeginning(&head, 5);
    printf("3. After inserting 5 at beginning:\n");
    traverseList(head);

    insertAtPosition(&head, 25, 3);
    printf("4. After inserting 25 at position 3:\n");
    traverseList(head);

    struct Node *node_10 = head->next;
    insertAfterNode(node_10, 15);
    printf("5. After inserting 15 after node 10:\n");
    traverseList(head);

    printf("\n");
    freeList(head);
    return 0;
}
