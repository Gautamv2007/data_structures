#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void insert_begin() {
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  scanf("%d", &temp->data);
  if (head == NULL){
    head = temp;
    head->next = NULL;
  }
  else{
    temp->next = head;
    head = temp;
  }
}

void insert_end(){
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  scanf("%d", &temp->data);
  if (head == NULL){
    head = temp;
    head->next = NULL;
  }
  else{
    struct node *p;
    p = head;
    while(p->next != NULL){
      p = p->next;
    }
    p->next = temp;
    temp->next = NULL;
  }
}

void insert_position(){
  int pos;
  struct node *temp, *p;
  temp = (struct node*)malloc(sizeof(struct node));
  scanf("%d %d", &pos, &temp->data);
  if (head == NULL){
    head = temp;
    head->next = NULL;
  }
  else{
    p = head;
    for(int i = 1;i<pos;i++){
      p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
  }
}

void delete_begin(void){
  struct node *p;
  p = head;
  head = head->next;
  printf("%d", p->data);
  free(p);
}

void delete_last(void){
  struct node *p, *q;
  p = head;
  if (head->next == NULL){
    free(head);
    head = NULL;
    return;
  }
  else {
    while(p->next != NULL){
      q = p;
      p = p->next;
    }
    q->next = NULL;
    free(p);
  }
}

void display(){
  struct node *p;
  p = head;
  while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void reverse(void){
  struct node *prev = NULL;
  struct node *curr = head;
  struct node *next = NULL;
  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

void sort(void){
  struct node *p = head;
  int n = 0;
  while(p != NULL){
    n++;
    p = p->next;
  }

  int arr[n];
  p = head;
  for(int i = 0;i<n;i++){
    arr[i] = p->data;
    p = p->next;
  }
  for(int i = 0;i<n;i++){
    for(int j = i;j<n;j++){
      if (arr[i] > arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp; 
      }
    }
  }
  p = head;
  for(int i = 0;i<n;i++){
    p->data = arr[i];
    p = p->next;
  }
}

int main(){
  while(1){
    int ch;
    scanf("%d", &ch);
    switch(ch) {
      case 1:
        insert_begin();
        break;
      case 2:
        insert_end();
        break;
      case 3:
        insert_position();
        break;
      case 4:
        delete_begin();
        break;
      case 5:
        delete_last();
        break;
      case 6:
        display();
        break;
      case 7:
          reverse();
          break;
      case 8:
        sort();
        break;
      case 9:
        printf("Exiting the program...");
        return 0;
    }
  }
  return 0;
}
