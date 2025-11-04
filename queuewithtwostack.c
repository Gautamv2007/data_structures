#include <stdio.h>

int stack1[100];
int stack2[100];

int top1 = -1;
int top2 = -1;

void push(int num, int data){
    if (num == 1){
        stack1[++top1] = data;
    }
    else if(num == 2){
        stack2[++top2] = data;
    }
}

int pop(int num){
    if (num == 1){
        return stack1[top1--];
    }
    else if (num == 2) return stack2[top2--];
    return 0;
}

void enqueue(int data){
    while(top1 != -1){
        push(2, pop(1));
    }
    push(1, data);
    while(top2 != -1){
        push(1, pop(2));
    }
}

int dequeue(void){
    int k = pop(1);
    printf("%d", k);
    return k;
}

int main(){
    while(1){
        int ch;
        scanf("%d", &ch);
        switch(ch){
            case 1:
                int data;
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                return 0;
                break;
        }
    }
}
