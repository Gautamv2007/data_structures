#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node *head = NULL;

void enqueue(int n){
  if (head == NULL){
    head = malloc(sizeof(struct node));
    head->next = NULL;
    head->data = n;
  }
  else {
    struct node *p;
    p = head;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    while(p->next != NULL){
      p = p->next;
    }
    p->next = temp;
    temp->next = NULL;
  }
}

void dequeue(void){
  struct node *p;
  p = head;
  head = p->next;
  free(p);
}

void display(void){
  struct node *p;
  p = head;
  while(p->next != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
}

int main(void){
  while(1){
    int ch;
    scanf("%d", &ch);
    switch(ch){
      case 1:
        int n;
        scanf("%d", &n);
        enqueue(n);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        return 0;
    }
  }
}
