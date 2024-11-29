#include <stdio.h>

void main() {
    int len, i, j, temp;
    
    printf("Enter the array length: ");
    scanf("%d", &len);
    
    int arr[len];
    
    printf("Enter array elements: ");
    for (i = 0; i < len; i++)
        scanf("%d", &arr[i]);
        
    printf("\nUnsorted array\t: ");
    for (i = 0; i < len; i++)
        printf("%d \t", arr[i]);
        
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("\nSorted array\t: ");
    for (i = 0; i < len; i++)
        printf("%d \t", arr[i]);
}
