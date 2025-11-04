#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *prev;
  struct node *next;
};

struct node *head = NULL;

void ins_begin(void){
  int data;
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  scanf("%d", &temp->data);
  if (head == NULL){
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
  }
  else {
    head->prev = temp;
    temp->next = head;
    temp->prev = NULL;
    head = temp;
  }
}

void ins_end(void){
  struct node *p, *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  scanf("%d", &temp->data);
  if (head == NULL){
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
  }
  else{
    p = head;
    while(p->next != NULL){
      p = p->next;
    }
    p->next = temp;
    temp->prev = p;
    temp->next = NULL;
  }
}

void ins_pos(void){
  struct node *temp, *p;
  int pos;
  temp = (struct node*)malloc(sizeof(struct node));
  scanf("%d %d", &pos, &temp->data);
  p = head;
  for(int i = 0;i<pos-1;i++){
    p = p->next;
  }
  temp->next = p->next;
  temp->prev = p;
  p->next->prev = temp;
  p->next = temp;
}
void delete_begin(void){
  if (head == NULL){
    printf("No elements to delete.");
  }
  else {
    struct node *p;
    if (head->next == NULL){
      p = head;
      head = NULL;
      free(p);
    }
    else {
      p = head;
      head->next->prev = NULL;
      head = head->next;
      free(p);
    }
  }
}

void delete_end(void){
  struct node *p;
  p = head;
  while(p->next != NULL){
    p = p->next;
  }
  p->prev->next = NULL;
  free(p);
}

void delete_pos(void){
  int pos;
  scanf("%d", &pos);
  struct node *p;
  p = head;
  for(int i = 0;i<pos-1;i++){
    p = p->next;
  }
  p->prev->next = p->next;
  p->next->prev = p->prev;
  free(p);
}

void reverse(void){
  struct node *p, *temp = NULL;
  p = head;
  while(p != NULL){
    temp = p->prev;
    p->prev = p->next;
    p->next = temp;
    p = p->prev;
  }
  head = temp->prev;
}

void display(void){
  struct node *p;
  p = head;
  while(p != NULL){
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
        ins_begin();
        break;
      case 2:
        display();
        break;
      case 3:
        ins_end();
        break;
      case 4:
        ins_pos();
        break;
      case 5:
        delete_begin();
        break;
      case 6:
        delete_end();
        break;
      case 7:
        delete_pos();
        break;
      case 8:
        reverse();
        break;
      case 9:
        return 0;
    }
  }
}
