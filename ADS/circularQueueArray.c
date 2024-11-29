#include <stdio.h>
#include <stdlib.h>

void enqueue();
void display();
void dequeue();
#define size 5
int arr[size], data, front = -1, rear = -1;

void main() {
    int item, ch, ch1;

    do {
        printf("\n---Main Menu---\n\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid choice");
        }
    } while (ch < 5 && ch > 0);
}

void enqueue() {
    if ((rear + 1) % size == front) {
        printf("\nQueue is full, cannot enqueue\n");
        return;
    }
    if (front == -1)
        front = 0;

    rear = (rear + 1) % size;
    printf("\nEnter data value : ");
    scanf("%d", &data);
    arr[rear] = data;
    printf("Node enqueued : %d\n", data);
}

void dequeue() {
    if (front == -1) {
        printf("\nQueue is empty, nothing to dequeue\n");
        return;
    }

    data = arr[front];
    printf("Node dequeued : %d\n", data);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
}

void display() {
    printf("\n---DISPLAY---\n");

    if (front == -1) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("Queue: \n");
    int i = front;
    while (1) {
        printf("%d\n", arr[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
}
