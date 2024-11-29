#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void push();
void display();
void pop();

Node *create_node();

void main(){
    int item, ch, ch1;

    do{
        printf("\n---Main Menu---\n\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
            case 4: exit(0);
                break;
            default: printf("\nInvalid choice");
        }
    } while(ch < 5 && ch > 0);
}

void push(){
    Node *ptr = create_node();
    if(ptr != NULL){
        ptr->next = head;
        head = ptr;
        printf("Node pushed onto stack: %d\n", ptr->data);
    }
}

void pop(){
    if (head == NULL)
        printf("\nStack is empty, nothing to pop\n");  
    else{
        Node *temp = head;
        head = head->next;
        printf("Node popped from stack: %d\n", temp->data);
        free(temp);
    }
}

void display(){
    printf("\n---DISPLAY---\n");
    Node *temp = head;
    if (temp == NULL) {
        printf("\nStack is empty\n");
        return;
    }
    printf("Stack: \n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

Node *create_node(){
    Node *ptr = (Node *)malloc(sizeof(Node));
    if(ptr == NULL)
        printf("\nOverflow memory not allocated");
    else{
        printf("\nEnter data value : ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
    }
    return ptr;
}
