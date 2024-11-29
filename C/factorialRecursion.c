#include <stdio.h>

int fact(int);

void main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("\nFactorial of %d = %d\n", num, fact(num));
}

int fact(int num) {
    if (num == 0)
        return 1;
    else
        return num * fact(num - 1);
}
