#include <stdio.h>
#include <stdlib.h>

void enqueue();
void display();
void dequeue();

int arr[100], i = 0, data;

void main() {
    int ch;
    do {
        printf("\n---Main Menu---\n\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
            case 4: exit(0);
                break;
            default: printf("\nInvalid choice");
        }
    } while (ch < 5 && ch > 0);
}

void enqueue() {
    if (i < 100) {
        printf("\nEnter data value : ");
        scanf("%d", &data);
        arr[i] = data;
        i++;
        printf("Node enqueued : %d\n", data);
    } else {
        printf("\nMemory Overflow\n");
    }
}

void dequeue() {
    if (i == 0)
        printf("\nQueue is empty, nothing to dequeue\n");
    else {
        data = arr[0];
        printf("Node dequeued : %d\n", data);
        for (int j = 0; j < i - 1; j++)
            arr[j] = arr[j + 1];
        i--;
    }
}

void display() {
    printf("\n---DISPLAY---\n");

    if (i == 0) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("Queue: \n");
    for (int j = 0; j < i; j++)
        printf("%d\n", arr[j]);
}
