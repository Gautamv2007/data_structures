#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x){
    if (top >= MAX-1){
        printf("Overflow\n");
    } else {
        stack[++top] = x;
    }
}

char pop(){
    if (top == -1){
        return -1; // underflow
    } else {
        return stack[top--];
    }
}

char t(){
    if (top == -1) return -1;
    return stack[top];
}

int main(void){
    char exp[MAX];
    int flag = 0;
    scanf("%s", exp);

    for(int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if ((exp[i] == ')' && t() == '(') ||
                (exp[i] == '}' && t() == '{') ||
                (exp[i] == ']' && t() == '[')) {
                pop();
            } else {
                flag = 1;
                break;
            }
        }
    }

    if (top == -1 && flag == 0){
        printf("true\n");
    } else {
        printf("false\n");
    }
}
