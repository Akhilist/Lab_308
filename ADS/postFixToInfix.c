#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;
void push(int);
int pop();

void main() {
    char postfix[100];
    int i = 0;
    printf("\nEnter postfix: ");
    fgets(postfix, sizeof(postfix), stdin);
    while (postfix[i] != '\0' && postfix[i] != '\n') {
        if (postfix[i] == ' ' || postfix[i] == ',') {
            i++;
            continue;
        }
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            int operand2 = pop();
            int operand1 = pop();
            int res;
            if (operand1 == -1 || operand2 == -1) {
                printf("\nInsufficient operands\n");
                return;
            }
            switch (postfix[i]) {
                case '+': res = operand1 + operand2; break;
                case '-': res = operand1 - operand2; break;
                case '*': res = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {
                        printf("\nDivision by zero error\n");
                        return;
                    }
                    res = operand1 / operand2;
                    break;
                default: 
                    printf("\nInvalid operator\n");
                    return;
            }
            push(res);
        }
        i++;
    }

    printf("\nPostfix after evaluation = %d\n", pop());
}

void push(int ch) {
    if (top == 99) {
        printf("\nStack Overflow\n");
        return;
    }
    top++;
    stack[top] = ch;
}

int pop() {
    if (top == -1) {
        printf("\nStack underflow\n");
        return -1;
    }
    return stack[top--];
}
