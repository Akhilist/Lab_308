#include <stdio.h>

void main(){
	int len, i, ele, flag = 0;
	printf("Enter the array length : ");
	scanf("%d", &len);
	int arr[len];
	printf("Enter array elements : ");
	for(i=0; i<len; i++)
		scanf("%d", &arr[i]);
	printf("Enter element to search : ");
	scanf("%d", &ele);
	for(i=0; i<len; i++){
		if(arr[i] == ele){
			flag = 1;
			break;
		}
	}
	if(flag == 1)
		printf("Element found at position %d\n", i+1);
	else
		printf("Element not found\n");
	
}
#include <stdio.h>

void main() {
    int len, i, ele, flag = 0;
    
    printf("Enter the array length: ");
    scanf("%d", &len);
    
    int arr[len];
    
    printf("Enter array elements: ");
    for (i = 0; i < len; i++)
        scanf("%d", &arr[i]);
        
    printf("Enter element to search: ");
    scanf("%d", &ele);
    
    for (i = 0; i < len; i++) {
        if (arr[i] == ele) {
            flag = 1;
            break;
        }
    }
    
    if (flag == 1)
        printf("Element found at position %d\n", i + 1);
    else
        printf("Element not found\n");
}
