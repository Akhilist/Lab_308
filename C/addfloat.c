#include <stdio.h>

float add(float, float);

void main(){
    float a,b;
    printf("Enter two floating point values to add : ");
    scanf("%f %f", &a, &b);
    
    printf("%f + %f = %f \n", a, b, add(a, b));
}

float add(float a, float b){
    return a+b;
}
