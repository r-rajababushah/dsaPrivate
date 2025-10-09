#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

int pop() {
    if (head == NULL) {
        printf("STACK Underflow. Cannot pop \n");
        return -1;
    }
    Node *temp = head;
    int val = temp->data;
    head = head->next;
    free(temp);
    return val;
}

int top() { return head->data; }

void display() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
    free(temp);
}

int main() {
    push(5);
    push(6);
    push(7);
    push(8);
    display();
    printf("POPPED : %d\n", pop());
    printf("Top value : %d \n", top());
    display();
    return 0;
}