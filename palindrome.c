#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int main(void){
    char string[100];
    scanf("%s", string);
    for(int i = 0;string[i] != '\0';i++){
        if (isalpha(string[i])){
            push(string[i]);
        }
    }
    int len = strlen(string);
    int i = 0;
    bool b = true;
    while(i<top){
        if (string[i++] != pop()) {
            b = false;
            break;
        } 
    }
    if (b) printf("It is a palidrome.");
    else printf("It is not a palidrome.");
}