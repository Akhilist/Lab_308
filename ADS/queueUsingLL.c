#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;
Node *end = NULL;

void enqueue();
void display();
void dequeue();

Node *create_node();

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
    Node *ptr = create_node();
    if (ptr != NULL) {
        if (end == NULL) {
            head = end = ptr;
        } else {
            end->next = ptr;
            end = ptr;
        }
        printf("Node enqueued : %d\n", ptr->data);
    }
}

void dequeue() {
    if (head == NULL)
        printf("\nQueue is empty, nothing to dequeue\n");
    else {
        Node *temp = head;
        head = head->next;
        if (head == NULL)
            end = NULL;
        printf("Node dequeued : %d\n", temp->data);
        free(temp);
    }
}

void display() {
    printf("\n---DISPLAY---\n");
    Node *temp = head;
    if (temp == NULL) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("Queue: \n");
    while (temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

Node *create_node() {
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL) {
        printf("\nOverflow memory not allocated\n");
        return NULL;
    } else {
        printf("\nEnter data value : ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
    }
    return ptr;
}
