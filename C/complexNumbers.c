#include <stdio.h>

void main() {
    int realA, realB, imagA, imagB;
    
    printf("Enter the real part of the first complex number: ");
    scanf("%d", &realA);
    
    printf("Enter the imaginary part of the first complex number: ");
    scanf("%d", &imagA);
    
    printf("Enter the real part of the second complex number: ");
    scanf("%d", &realB);
    
    printf("Enter the imaginary part of the second complex number: ");
    scanf("%d", &imagB);
    
    printf("\n(%d + i%d) + (%d + i%d) = %d + i%d\n", realA, imagA, realB, imagB, (realA + realB), (imagA + imagB));
}
