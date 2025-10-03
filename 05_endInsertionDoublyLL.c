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

    printf("Doubly Linked List Operations (Insert at Beginning & End)\n");
    printf("-------------------------------------------------------\n");

    printf("1. Initial list:\n");
    traverseList(head);
    reverseTraverseList(head);
    printf("\n");

    insertAtBeginning(&head, 10);
    printf("2. After inserting 10 at beginning:\n");
    traverseList(head);
    reverseTraverseList(head);

    insertAtEnd(&head, 30);
    printf("3. After inserting 30 at end:\n");
    traverseList(head);
    reverseTraverseList(head);

    insertAtBeginning(&head, 5);
    printf("4. After inserting 5 at beginning:\n");
    traverseList(head);
    reverseTraverseList(head);

    insertAtEnd(&head, 40);
    printf("5. After inserting 40 at end:\n");
    traverseList(head);
    reverseTraverseList(head);

    printf("\nFinal list cleanup.\n");
    freeList(head);
    return 0;
}
