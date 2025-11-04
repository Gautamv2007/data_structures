#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *p = NULL;

int height(struct node *p){
    if (p == NULL){
        return 0;
    }
    return p->height;
}

int max(int a, int b){
    return (a < b)? b:a;
}

struct node* createNode(int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

struct node* right_rotate(struct node *y){
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = max(height(x->right), height(x->left));
    y->height = max(height(y->right), height(y->left));

    return x;
}

struct node* left_rotate(struct node *x){
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(height(y->left), height(y->right));
    x->height = max(height(x->left), height(y->right));

    return y;
}


int getBalance(struct node *p){
    if (p == NULL) return 0;
    return height(p->left) - height(p->right);
}


struct node* insert(struct node* p, int data){
    if (p == NULL) {
        return createNode(data);
    }
    if (data < p->data){
        p->left = insert(p->left, data);
    }
    else if (data > p->data){
        p->right = insert(p->right, data);
    }
    else return p;

    p->height = 1 + max(height(p->left), height(p->right));


    int balance = getBalance(p);

    if (balance > 1 && data < p->left->data){
        return right_rotate(p);
    }
    else if (balance > 1 && data > p->left->data){
        p->left = left_rotate(p->left);
        return right_rotate(p);
    }
    else if (balance < -1 && data > p->right->data){
        return left_rotate(p);
    }
    else if (balance < -1 && data < p->right->data){
        p->right = right_rotate(p->right);
        return left_rotate(p);
    }
    return p;
}


void inorder(struct node *p){
    if (p == NULL) return;
    inorder(p->left);
    printf("%d ", p->data);
    inorder(p->right);
}

struct node *min(struct node *p){
    struct node *current = p;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}


struct node* deletenode(struct node* p, int data){
    if (p == NULL){
        return p;
    }
    if (data < p->data){
        p->left = deletenode(p->left, data);
    }
    else if (data > p->data){
        p->right = deletenode(p->right, data);
    }
    else {
        if (p->left == NULL || p->right == NULL){
            struct node *temp = p->left ? p->left : p->right;

            if (temp == NULL){
                temp = p;    
                p = NULL;
            }
            else {
                *p = *temp;
            }
            free(temp);
        }
        else {
            struct node *temp = min(p->right);
            p->data = temp->data;
            p->right = deletenode(p->right, data);
        }
    }
    if (p == NULL){
        return p;
    }
    p->height = 1 + max(height(p->left), height(p->right));
    int balance = getBalance(p);

    if (balance > 1 && data < p->left->data){
        return right_rotate(p);
    }
    else if (balance > 1 && data > p->left->data){
        p->left = left_rotate(p->left);
        return right_rotate(p);
    }
    else if (balance < -1 && data > p->right->data){
        return left_rotate(p);
    }
    else if (balance < -1 && data < p->right->data){
        p->right = right_rotate(p->right);
        return left_rotate(p);
    }
    return p;
}

int main(void){
    p = insert(p, 1);
    p = insert(p, 4);
    p = insert(p, 3);
    p = insert(p, 2);

    inorder(p);
    p = deletenode(p, 3);
    printf("\n");
    inorder(p);
}




