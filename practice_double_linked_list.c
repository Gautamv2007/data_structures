#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void ins_begin(void){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &temp->data);
    if (head == NULL){
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
        return;
    }
    temp->prev = NULL;
    temp->next = head;
    head = temp;
}

void delete_end(void){
    struct node *p;
    p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

void ins_end(void){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &temp->data);
    if (head == NULL){
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
        return;
    }

    struct node *p;
    p = head;
    while(p->next != NULL){
        p = p->next;
    }
    temp->next = NULL;
    temp->prev = p;
    p->next = temp;
}

void delete_begin(void){
    struct node *p;
    p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
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
                delete_end();
                break;
            case 4:
                ins_end();
                break;
            case 5:
                delete_begin();
                break;
        }
    }
}