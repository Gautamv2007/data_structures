#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **p, int n){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    if (*p == NULL){
        *p = temp;
        return;
    }
    struct node *curr = *p;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
}

int pop(struct node **p){
    struct node *curr = *p;

    if (curr->next == NULL){
        int k = curr->data;
        free(curr);
        *p = NULL;
        return k;
    }

    while(curr->next->next != NULL){
        curr = curr->next;
    }
    int k = curr->next->data;
    free(curr->next);
    curr->next = NULL;
    return k;
}

void display(struct node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

void enqueue(struct node **p1,int n){
    push(p1, n);
}

int dequeue(struct node **p1, struct node **p2){
    int n = 1;
    struct node *curr = *p1;
    while(curr->next != NULL){
        curr = curr->next;
        n++;
    }
    for(int i = 1;i<n;i++){
        int k = pop(p1);
        push(p2, k);
    }
    int ret = pop(p1);
    for(int i = 1;i<n;i++){
        int k = pop(p2);
        push(p1, k);
    }
    return ret;
}

int main(void){
    struct node *p1 = NULL;
    struct node *p2 = NULL;
    while(1){
        int ch;
        scanf("%d", &ch);
        switch(ch){
            case 1:
                int k;
                scanf("%d", &k);
                enqueue(&p1, k);
                break;
            case 2:
                dequeue(&p1, &p2);
                break;
            case 3:
                display(p1);
                break;
        }
    }
}