#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **head, int d){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = d;
	if (*head == NULL){
		temp->next = NULL;
		*head = temp;
	}
	else {
		temp->next = *head;
		*head = temp;
	}
}

int pop(struct node **head){
	struct node *p;
	p = *head;
	if(*head == NULL){
		printf("Underflow");
	}
	else {
		int val = p->data;
		*head = p->next;
		free(p);
		printf("%d",val); 
	}
}

int peek(struct node *head){
	int val = head->data;
	printf("%d", val);
}

void display(struct node *head){
	struct node *p;
	p = head;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
}

int main(void){
	struct node *head = NULL;
	while(1){
		int ch;
		scanf("%d", &ch);
		switch(ch){
			case 1:
				int d;
				scanf("%d", &d);
				push(&head, d);
				break;
			case 2:
				pop(&head);
				break;
			case 3:
				peek(head);
				break;
			case 4:
				display(head);
				break;
			case 5:
				return 0;
		}
	}
}

