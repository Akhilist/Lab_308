#include <stdio.h>
#include <stdlib.h>

int sequentialSearch(int[], int, int);
int binarySearch(int[], int, int);

void main() {
    int x, n, result, ch = 0;

    printf("Enter array size : ");
    scanf("%d", &n);
    int array[n];

    printf("Enter array elements : \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Enter element to search : ");
    scanf("%d", &x);

    printf("---Main Menu---\n");
    printf("1. Sequential Search\n2. Binary Search\n3. Exit\nEnter your choice : ");
    scanf("%d", &ch);
    switch (ch) {
        case 1: result = sequentialSearch(array, n, x);
            break;
        case 2: result = binarySearch(array, n, x);
            break;
        case 3: exit(0);
            break;
        default: printf("\nInvalid choice !\n");
    }

    if (result == -1)
        printf("\nElement not found \n");
    else
        printf("\nElement found at position : %d\n", result + 1);
}

int sequentialSearch(int array[], int n, int x) {
    printf("\nSequential Search");
    printf("\nArray \t: ");
    for (int i = 0; i < n; i++)
        printf("%d \t", array[i]);

    for (int i = 0; i < n; i++) {
        if (array[i] == x)
            return i;
    }
    return -1;
}

int binarySearch(int array[], int n, int x) {
    printf("\nBinary Search");
    int low = 0, temp;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("\nArray after sorting\t: ");
    for (int i = 0; i < n; i++)
        printf("%d \t", array[i]);

    while (low <= n) {
        int mid = low + (n - low) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] < x)
            low = mid + 1;
        else
            n = mid - 1;
    }
    return -1;
}
