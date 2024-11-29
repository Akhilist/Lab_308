#include <stdio.h>

void main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    int *x = &a, *y = &b;
    
    printf("\nAddress of %d : *x : %p", a, x);
    printf("\nAddress of %d : *y : %p", b, y);
    
    printf("\n*x + *y = %d", (*x + *y));
    printf("\n*x - *y = %d", (*x - *y));
    printf("\n*x * *y = %d\n\n", (*x * *y));
}
