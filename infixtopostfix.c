#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x){
  if (top >= MAX-1){
    printf("Stack overflow");
  }
  else {
    stack[++top] = x;
  }
}

char pop(){
  if (top == -1){
    return -1;
  }
  else {
    return stack[top--];
  }
}

int precedence(char x){
  if (x == '(') return 0;
  if (x == '+' || x == '-') return 1;
  if (x == '*' || x == '/') return 2;
  if (x == '^') return 3;
  return -1;
}

void infixtopostfix(char infix[]){
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
  printf("\n");
}

int main(void){
  char exp[MAX];
  scanf("%s", exp);

  infixtopostfix(exp);
}
