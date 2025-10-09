# Data Structures and Searching Programs in C

This document contains implementations of common searching techniques and linked list operations in C.

---

## 1. Linear Search in an Array
##### 7/08/25
```c
// write a program to perform a linear search in a given array in C
```

---

## 2. Binary Search in an Array
## 8/08/25
```c
// write a program to perform binary search in an array
```

---

## 3. Singly Linked List Operations
## 14/08/25
```c
// write a program to create a linked list and perform following operations:
// 1. traversal
// 2. insert a node at the beginning
// 3. insert a node after a given node
// 4. insert a node after the specific position
// 5. insert a node at the end of the list
```

---

## 4. Doubly Linked List - Insert at Beginning
## 18/09/25
```c
// write a program in doubly linked list for inserting a node at beginning
```

---

```
### 5. ```// write a program in doubly linked list for insertion of node at the end```
#### 19/09/25
```

### 7. ```// write a program of deletion at the beginning from doubly linked list```
#### 25/09/25

---

### 9. ```// write a program in c that implements stack using an array.```
#### 03-Oct-25
######
 ``` 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10

int stack[MAX], top;

void display(int[]);
void push(int[], int);
void pop(int[]);

void main(){
    int ITEM = 0;
    int choice = 0;
    top = -1;
    while(1){
        printf("Enter choice (1. display, 2. insert, 3. remove, 4. exit ...))\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                display(stack);
                break;
            case 2:
                printf("Enter item to be insert: ");
                scanf("%d", &ITEM);
                push(stack, ITEM);
                break;
            case 3:
                pop(stack);
                break;
            case 4:
                exit(0);
            default:
                printf("\n Invalid choice\n");
                break;
        }
        getch();
    }
}

void display(int stack[]){
    int i = 0;
    if(top == -1){
        printf("stack is empty \n");
        return;
    }
    printf("%d <--- Top\n", stack[top]);
    for (i = top - 1; i >= 0; i--){
        printf("%d\n", stack[i]);
    }
    printf("\n");
}

void push(int stack[], int ITEM){
    if(top == MAX - 1){
        printf("Stack Overflow: Cannot insert %d\n", ITEM);
        return;
    }
    top++;
    stack[top] = ITEM;
}

void pop(int stack[]){
    if(top == -1){
        printf("Stack Underflow: Cannot remove element\n");
        return;
    }
    printf("Item popped: %d\n", stack[top]);
    top--;
}
```