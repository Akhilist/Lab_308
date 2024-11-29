#include <stdio.h>
#include <stdlib.h>

void swapByValue(int, int);
void swapByReference(int*, int*);

void main() {
    int a, b, ch = 0;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("Before swap:\n");
    printf("Element 1: %d\nElement 2: %d", a, b);
    
    do {
        printf("\n\n---Main Menu---\n1. Call By Value\n2. Call By Reference\n3. Exit\n\nEnter your choice: ");
        scanf("%d", &ch);
        
        if (ch == 1 || ch == 2)
            printf("\nAfter swap:\n");
        
        switch (ch) {
            case 1:
                swapByValue(a, b);
                break;
            case 2:
                swapByReference(&a, &b);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice!");
        }
    } while (ch > 0 && ch < 4);
}

void swapByValue(int a, int b) {
    int c;
    c = a;
    a = b;
    b = c; 
    
    printf("Call By Value\nElement 1: %d\nElement 2: %d", a, b);
}

void swapByReference(int* a, int* b) {
    int c;
    c = *a;
    *a = *b;
    *b = c; 
    
    printf("Call By Reference\nElement 1: %d\nElement 2: %d", *a, *b);
}
