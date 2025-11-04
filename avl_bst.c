#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int height(struct node *p){
    if (p == NULL){
        return 0;
    }
    return p->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int getbalance(struct node *p){
    if (p == NULL){
        return 0;
    }
    return height(p->left) - height(p->right);
}
struct node* createnode(int key){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}

struct node* left_rotate(struct node *p){
    struct node *y = p->right;
    struct node *t2 = y->left;

    y->left = p;
    p->right = t2;

    p->height = max(height(p->left), height(p->right));
    y->height = max(height(y->left), height(y->right));

    return y;
}

struct node* right_rotate(struct node *p){
    struct node *x = p->left;
    struct node *t2 = x->right;

    x->right = p;
    p->left = t2;
    
    p->height = max(height(p->left), height(p->right));
    x->height = max(height(x->left), height(p->right));

    return x;
}

struct node* insert(struct node* p, int key){
    if (p == NULL){
        return createnode(key);
    }
    else if (key < p->key){
        p->left = insert(p->left, key);
    }
    else if (key > p->key){
        p->right = insert(p->right, key);
    }
    else return p;

    p->height = 1 + max(height(p->left), height(p->right));
    int balance = getbalance(p);

    if (balance > 1 && key < p->left->key){
        return right_rotate(p);
    }
    else if (balance > 1 && key > p->right->key){
        p->left = left_rotate(p->left);
        return right_rotate(p);
    }
    else if (balance < -1 && key > p->right->key){
        return left_rotate(p);
    }
    else if (balance < -1 && key < p->right->key){
        p->right = right_rotate(p->right);
        return left_rotate(p);
    }
    return p;
}

struct node* min(struct node *p){
    struct node *current = p;
    while(p->left != NULL){
        p = p->left;
    }
    return current;
}

struct node* del(struct node* p, int key){
    if (p == NULL){
        return p;
    }
    else if(key < p->key){
        p->left = del(p->left, key);
    }
    else if (key > p->key){
        p->right = del(p->right, key);
    }
    else {
        if((p->left == NULL) || (p->right == NULL)){
            struct node *temp = p->left ? p->left : p->right;
            if (temp == NULL){
                temp = p;
                p = NULL;
            }
            else{
                *p = *temp;
            }
            free(temp);
        }
        else {
            struct node *temp = min(p->right);
            p->key = temp->key;
            p->right = del(p->right, temp->key);
        }
    }
    if (p == NULL){
        return p;
    }
    p->height = 1 + max(height(p->left), height(p->right));
    int balance = getbalance(p);
    if (balance > 1 && key < p->left->key){
        return right_rotate(p);
    }
    else if (balance > 1 && key > p->right->key){
        p->left = left_rotate(p->left);
        return right_rotate(p);
    }
    else if (balance < -1 && key > p->right->key){
        return left_rotate(p);
    }
    else if (balance < -1 && key < p->right->key){
        p->right = right_rotate(p->right);
        return left_rotate(p);
    }
    return p;
}

void inorder(struct node *p){
    if (p == NULL) return;
    inorder(p->left);
    printf("%d ", p->key);
    inorder(p->right);
}

int main(void){
    struct node *head = NULL;
    while(1){
        int ch;
        scanf("%d", &ch);
        if (ch == 1){
            int k;
            scanf("%d", &k);
            head = insert(head, k);
        }
        else if (ch == 2){
            inorder(head);
        }
        else if (ch == 3){
            int q;
            scanf("%d", &q);
            head = del(head, q);
        }
        else if (ch == 4){
            return 0;
        }
    }
}

        



