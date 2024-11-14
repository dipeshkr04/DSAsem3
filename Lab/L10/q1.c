//1) Create binary search tree and perform following operation on it Traverse,Insert,Delete

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void info(){
    time_t t;
    time(&t);
    printf("DIPESH KUMAR\nBT23CSH043\n\n%s\n",ctime(&t));
    return;
}

struct node{
    struct node *lft;
    int data;
    struct node *rgt;
};

struct node *binaryTreeInsert(struct node *root, int el){
    if(root==NULL){
        struct node *temp=malloc(sizeof(struct node));
        temp->data=el;
        temp->lft=NULL;
        temp->rgt=NULL;
        return temp;
    }
    if(el>=root->data){
        root->rgt=binaryTreeInsert(root->rgt,el);
    }
    else{
        root->lft=binaryTreeInsert(root->lft,el);
    }
    return root;
}

struct node *binaryTreeDel(struct node *root, int el){
    if(root==NULL){
        return NULL;
    }
    else if(root->data==el){
        
    }
}
void preOrder(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        printf("%d\t",root->data);
        preOrder(root->lft);
        preOrder(root->rgt);
        return;
    }
}

void postOrder(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        postOrder(root->lft);
        postOrder(root->rgt);
        printf("%d\t",root->data);
        return;
    }
}

void inOrder(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        inOrder(root->lft);
        printf("%d\t",root->data);
        inOrder(root->rgt);
        return;
    }
}

int main(){
    info();
    struct node *root=NULL;
    // int t;
    // scanf("%d");
    while(1){
        int n;
        printf("Enter data for new node (-1 for exit inserting)...");
        scanf("%d",&n);
        switch(n){
            case -1:
                goto start;
            default:
                root=binaryTreeInsert(root,n);
        }
    }
    start:
    printf("\nPre Order :-\t");
    preOrder(root);
    printf("\nIn Order :-\t");
    inOrder(root);
    printf("\nPost Order :-\t");
    postOrder(root);
    return 0;
}