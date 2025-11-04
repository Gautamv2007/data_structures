#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void enqueue(struct node **p){
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  scanf("%d", &temp->data);
  if (*p == NULL){
    temp->next = NULL;
    *p = temp;
    return;
  }
  struct node *curr = *p;
  while(curr->next != NULL) curr = curr->next;
  temp->next = NULL;
  curr->next = temp;
}

void display(struct node *p){
  while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
}


int main(void){
  struct node *q1 = NULL;
  while(1){
    int ch;
    scanf("%d", &ch);
    switch(ch){
      case 1:
        enqueue(&q1);
        break;
      case 2:
        display(q1);
        break;
    }
  }
}
