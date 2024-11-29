#include <stdio.h>
#include <stdlib.h>

void push();
void display();
void pop();

int arr[100], i = 0, data;

void main() {
    int item, ch, ch1;

    do {
        printf("\n---Main Menu---\n\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch) {
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

void push() {
    if(i < 100) {
        printf("\nEnter data value : ");
        scanf("%d", &data);
        arr[i] = data;
        i++;
        printf("Node pushed onto stack: %d\n", data);
    } else {
        printf("\nStack Overflow\n");
    }
}

void pop() {
    if (i == 0)
        printf("\nStack is empty, nothing to pop\n");
    else {
        i--;
        data = arr[i];
        arr[i] = 0;
        printf("Node popped from stack: %d\n", data);
    }
}

void display() {
    printf("\n---DISPLAY---\n");
    if (i == 0) {
        printf("\nStack is empty\n");
        return;
    }
    printf("Stack: \n");
    for(int j = i; j > 0; j--)
        printf("%d\n", arr[j - 1]);
}
