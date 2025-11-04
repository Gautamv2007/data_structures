#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(void){
    struct node *temp, *p, *q;
    temp = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL){
        root = temp;
        return;
    }
    p = root;
    while(p != NULL){
        if (temp->data < p->data){
            q = p;
            p = p->left;
        }else {
            q = p;
            p = p->right;
        }
    }
    if (temp->data < q->data){
        q->left = temp;
    }
    else {
        q->right = temp;
    }
}

struct node *min(struct node *p){
    if (p == NULL) return NULL;
    while(p->left != NULL){
        p = p->left;
    }
    return p;
}

struct node *delete(struct node *root, int n){
    if (n < root->data){
        root->left = delete(root->left, n);
    }
    else if (n > root->data){
        root->right = delete(root->right, n);
    }
    else {
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else {
            struct node *m = min(root->right);
            root->data = m->data;
            root->right = delete(root->right, m->data);
        }
    }
    return root;
}


void inorder(struct node *p){
    if(p == NULL) return;
    inorder(p->left);
    printf("%d ", p->data);
    inorder(p->right);
}

void preorder(struct node *p){
    if (p == NULL) return;
    printf("%d ", p->data);
    preorder(p->left);
    preorder(p->right);
}

void postorder(struct node *p){
    if (p == NULL) return;
    postorder(p->left);
    postorder(p->right);
    printf("%d ", p->data);
}

int main(){
    while(1){
        int ch;
        scanf("%d", &ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                int k;
                scanf("%d", &k);
                delete(root, k);
                break;
            case 6:
                return 0;
        }
    }
}
