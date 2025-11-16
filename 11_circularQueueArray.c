#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 5

// Structure to represent the circular queue
struct CircularQueue {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
};

// Function to initialize the queue
void initializeQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue *q) { return q->size == 0; }

// Function to check if the queue is full
int isFull(struct CircularQueue *q) { return q->size == MAX_SIZE; }

// Function to add an element to the queue (enqueue)
void enqueue(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0; // Set front to 0 if queue is empty
    }

    // Increment rear circularly
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    q->size++;
    printf("%d enqueued to the queue\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1; // Return -1 to indicate error
    }

    int value = q->items[q->front];
    q->items[q->front] = -1; // Optional: Clear the slot
    q->size--;

    if (isEmpty(q)) {
        q->front = -1;
        q->rear = -1;
    } else {
        // Increment front circularly
        q->front = (q->front + 1) % MAX_SIZE;
    }

    printf("%d dequeued from the queue\n", value);
    return value;
}

// Function to display the queue
void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    int count = 0;

    while (count < q->size) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    printf("\n");
}

// Main function to test the circular queue
int main() {
    struct CircularQueue q;
    initializeQueue(&q);

    // Test enqueue operations
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // Should indicate queue is full
    display(&q);

    // Test dequeue operations
    dequeue(&q);
    dequeue(&q);
    display(&q);

    // Test enqueue after dequeue (to demonstrate circular reuse)
    enqueue(&q, 60);
    enqueue(&q, 70);
    display(&q);

    return 0;
}