#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

void enqueue(struct node **p, int data){
    struct node *q = *p;
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->next = NULL;

    if (*p == NULL){
        *p = temp;
        return;
    }

    while(q->next != NULL){
        q = q->next;
    }

    q->next = temp;
}

int dequeue(struct node **p){
    struct node *q = *p;

    if (q->next == NULL){
        int k = q->data;
        free(*p);
        *p = NULL;
        return k;
    }

    int k = q->data;
    *p = q->next;
    free(q);
    return k;
}


void display(struct node *p){
    struct node *q = p;
    while(q != NULL){
        printf("%d ", q->data);
        q = q->next;
    }
}

bool isEmpty(struct node *p){
    return (p == NULL);
}



int main(void){
    struct node *q = NULL;

    int node;
    int arr[7][7] = {0};

    int edge, vertices;
    scanf("%d", &edge);
    for(int i = 0;i<edge;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        arr[u-1][v-1] = 1;
        arr[v-1][u-1] = 1;
    }
    int i = 0;
    int visited[7] = {0};
    printf("%d", i);
    enqueue(&q, i);
    while(!isEmpty(q)){
        node = dequeue(&q);
        for(int j = 0;j<7;j++){
            if (arr[node][j] == 1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

}

