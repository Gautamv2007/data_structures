#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int top = -1;

char stack[100][100];

void push(char *str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main(void) {
    char exp[100];
    printf("Enter postfix expression: ");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (!isOperator(exp[i])) {
            char operand[2] = {exp[i], '\0'};
            push(operand);
        } else {
            char op2[100], op1[100], result[100];

            strcpy(op2, pop()); 
            strcpy(op1, pop());  
            sprintf(result, "(%s %c %s)", op1, exp[i], op2);

            push(result);
        }
    }

    printf("Infix Expression: %s\n", pop());
    return 0;
}


