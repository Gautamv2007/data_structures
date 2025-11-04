#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100][100];
int top = -1;

void push(char *str){
    strcpy(stack[++top], str);
}

char* pop(){
    return stack[top--];
}

int isOperator(char c){
    return (c == '+' || c == '*' || c == '/' || c == '-');
}

int main(void){
    char prefix[100];
    scanf("%s", prefix);
    int len = strlen(prefix);
    for(int i = len - 1;i>=0;i--){
        char c = prefix[i];
        if (isalnum(c)){
            char op[2] = {c, '\0'};
            push(op);
        }
        else if (isOperator(c)){
            char op1[100], op2[100], temp[200];
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(temp, "%s%s%c", op1, op2, c);
            push(temp);
        }
    }
    printf("%s", stack[top]);
}
