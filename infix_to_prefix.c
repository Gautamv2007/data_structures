#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void reverse(char *exp){
    int len = strlen(exp);
    for(int i = 0;i<len/2;i++){
        char temp = exp[i];
        exp[i] = exp[len-i-1];
        exp[len-i-1] = temp;
    }
}

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char c){
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}


void infixtoprefix(char *infix, char *prefix){
    reverse(infix);
    int j = 0;
    for(int i = 0;infix[i] != '\0';i++){
        char c = infix[i];
        if (isalnum(c)){
            prefix[j++] = c;
        }
        else if (c == ')'){
            push(c);
        }
        else if (c == '('){
            while(top != -1 && peek() == ')'){
                prefix[j++] = pop();
            }
        }
        else {
            while(top != -1 && precedence(c) < precedence(peek())){
                prefix[j++] = pop();
            }
            push(c);
        }
    }
    while(top != -1){
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    reverse(prefix);
}

int main(void){
    char ex[100], out[100];
    scanf("%s", ex);
    infixtoprefix(ex, out);
    printf("%s", out);
}