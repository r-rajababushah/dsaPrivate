#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverseList(struct Node *head)
{
    struct Node *current = head;
    printf("Forward Traversal: ");
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void reverseTraverseList(struct Node *head)
{
    struct Node *current = head;
    if (current == NULL)
    {
        printf("Reverse Traversal: NULL\n");
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    printf("Reverse Traversal: ");
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
}

void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    struct Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void deleteAtBeginning(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty, deletion failed.\n");
        return;
    }

    struct Node *temp = *head_ref;

    *head_ref = (*head_ref)->next;

    if (*head_ref != NULL)
    {
        (*head_ref)->prev = NULL;
    }

    free(temp);
}

void freeList(struct Node *head)
{
    struct Node *current = head;
    struct Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    struct Node *head = NULL;

    printf("Doubly Linked List Operations (Insert & Delete at Beginning/End)\n");
    printf("---------------------------------------------------------------\n");

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 40);
    printf("1. Initial list after insertions (5 <-> 10 <-> 30 <-> 40):\n");
    traverseList(head);
    reverseTraverseList(head);
    printf("\n");

    deleteAtBeginning(&head);
    printf("2. After deleting node at beginning (Expected: 10 <-> 30 <-> 40):\n");
    traverseList(head);
    reverseTraverseList(head);
    printf("\n");

    deleteAtBeginning(&head);
    printf("3. After second deletion at beginning (Expected: 30 <-> 40):\n");
    traverseList(head);
    reverseTraverseList(head);
    printf("\n");

    deleteAtBeginning(&head);
    deleteAtBeginning(&head);
    printf("4. After deleting remaining nodes (Expected: Empty list):\n");
    traverseList(head);
    reverseTraverseList(head);
    printf("\n");

    deleteAtBeginning(&head);
    printf("5. Attempting deletion on empty list:\n");

    printf("\nFinal list cleanup (already empty).\n");
    freeList(head);
    return 0;
}
