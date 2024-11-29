#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;
char postfix[100];
int p = 0;

void push(char);
char pop();
int priority(char);
int operator(char);

void main() {
    char infix[100];
    int i = 0;
    printf("Enter infix: ");
    fgets(infix, sizeof(infix), stdin);
    while (infix[i] != '\0') {
        if (infix[i] == ' ' || infix[i] == ',') {
            i++;
            continue;
        }
        if (isalnum(infix[i])) {
            postfix[p] = infix[i];
            p++;
        } else if (infix[i] == '(')
            push(infix[i]);
        else if (operator(infix[i])) {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[p] = pop();
                p++;
            }
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[p] = pop();
                p++;
            }
            pop();
        }
        i++;
    }
    while (top != -1) {
        postfix[p] = pop();
        p++;
    }
    postfix[p] = '\0';
    printf("Postfix = %s\n", postfix);
}

void push(char ch) {
    if (top == 99) {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow");
        return 0;
    }
    return stack[top--];
}

int priority(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0;
}

int operator(char ch) {
    char op[] = { '+', '-', '*', '/', '^' };
    for (int i = 0; i < 5; i++) {
        if (ch == op[i])
            return 1;
    }
    return 0;
}
