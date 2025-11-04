#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

void insert(struct node **root, int data){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (*root == NULL){
        *root = temp;
        return;
    }

    struct node *p, *q;
    p = *root;
    while(p != NULL){
        if (p->data < data){
            q = p;
            p = p->right;
        }
        else{
            q = p;
            p = p->left;
        }
    }

    if (q->data < data){
        q->right = temp;
    }
    else {
        q->left = temp;
    }
}


struct node* min(struct node *p){
    struct node *current = p;
    while(current != NULL && current->right != NULL){
        current = current->right;
    }
    return current;
}

struct node *del(struct node *root, int data){
    if (root == NULL){
        return root;
    }
    if (data < root->data){
        root->right = del(root->left, data);
    }
    else if (data > root->data){
        root->right = del(root->right, data);
    }
    else {
        if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else {
            struct node *temp = min(root->left);
            root->data = temp->data;
            root->left = del(root->left, temp->data);
        }

    }
    return root;
}


void inorder(struct node *p){
    if (p == NULL) return;
    inorder(p->left);
    printf("%d ", p->data);
    inorder(p->right);
}

struct node *root = NULL;
int main(void){
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 3);
    inorder(root);
    printf("\n");
    del(root,4);
    inorder(root);
}
