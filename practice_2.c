#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void enqueue(struct node **p, int n){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n; 
    temp->next = NULL;
    if (*p == NULL){
        *p = temp;
        return;
    }
    struct node *cur = *p;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = temp;
}

int dequeue(struct node **p){
    struct node *curr = *p;
    *p = curr->next;
    int k = curr->data;
    free(curr);
    return k;
}


void push(struct node **p1, int n){
    enqueue(p1, n);
}

int pop(struct node **p1, struct node **p2){
    int n = 0;
    struct node *curr = *p1;
    while(curr != NULL){
        curr = curr->next;
        n++;
    }
    for(int i = 1;i<n;i++){
        int k = dequeue(p1);
        enqueue(p2, k);
    }
    int ret = dequeue(p1);
    for(int i = 1;i<n;i++){
        int k = dequeue(p2);
        enqueue(p1, k);
    }
    return ret;
}

void display(struct node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(void){
    struct node *p1 = NULL;
    struct node *p2 = NULL;
    while(1){
        int ch;
        scanf("%d", &ch);
        switch(ch){
            case 1:
                int a;
                scanf("%d", &a);
                push(&p1, a);
                break;
            case 2:
                int k = pop(&p1, &p2);
                break;
            case 3:
                display(p1);
                break;
        }
    }
}