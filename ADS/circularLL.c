#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;
Node* create_node();

void insert();
void display();
void delete();

void main() {
    int item, ch, ch1;

    do {
        printf("\n---Main Menu---\n\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
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

void insert() {
    Node* ptr = create_node();
    if (head == NULL) {
        head = ptr;
        ptr->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
    }
}

void delete() {
    if (head == NULL) {
        printf("\nList is empty, nothing to delete\n");
        return;
    }

    Node* temp = head;
    Node* to_delete = head;

    if (head->next == head) {
        head = NULL;
        printf("\nNode deleted : %d\n", to_delete->data);
        free(to_delete);
        return;
    }

    while (temp->next != head) {
        temp = temp->next;
    }

    head = head->next;
    temp->next = head;

    printf("\nNode deleted : %d\n", to_delete->data);
    free(to_delete);
}

void display() {
    printf("\nDISPLAY\n");
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

Node* create_node() {
    Node* ptr = (Node*)malloc(sizeof(Node));
    if (ptr == NULL)
        printf("\nOverflow memory not allocated");
    else {
        printf("\nEnter data value : ");
        scanf("%d", &ptr->data);
        ptr->next = head;
    }
    return ptr;
}
