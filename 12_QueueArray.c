#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int peek() {
    if (front == -1 || front > rear) return -1;
    return queue[front];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void printQueue() {
    if (front == -1 || front > rear) return;
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printQueue();
    printf("%d\n", dequeue());
    printQueue();
    printf("%d\n", peek());
    printf("%d\n", isEmpty());

    return 0;
}
