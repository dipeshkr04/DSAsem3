//1)create following binary tree using dynamic memory allocation and print the given ll in in-order pre-order and post-order

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

struct node *createTree(){
    int x;
    printf("Enter data for new node (Enter -1 to add no new node)...");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    else{
        struct node *temp=malloc(sizeof(struct node));
        temp->lft=createTree();
        temp->data=x;
        temp->rgt=createTree();
        return temp;
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
    struct node *root=createTree();
    printf("\nPre Order :-\t");
    preOrder(root);
    printf("\nIn Order :-\t");
    inOrder(root);
    printf("\nPost Order :-\t");
    postOrder(root);
    return 0;
}