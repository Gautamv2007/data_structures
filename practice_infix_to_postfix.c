#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c){
    stack[++top] = c;
}

char pop(void){
    return stack[top--];
}

int precedence(char x){
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
}


void convert(char infix[]){
    char *e, x;
    e = infix;
    while(*e != '\0'){
        if (isalnum(*e)){
            printf("%c", *e);
        }
        else if (*e == '('){
            push(*e);
        }
        else if (*e == ')'){
            while((x = pop()) != '('){
                printf("%c", x);
            }
        }

        else {
            while(top != -1 && precedence(stack[top]) >= precedence(*e)){
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while(top != -1){
        printf("%c", pop());
    }
}

int main(void){
    char s[100];
    printf("Enter the infix expression: ");
    scanf("%s", s);
    convert(s);
}