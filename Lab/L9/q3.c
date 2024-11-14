// 3)count number of leaf node in the tree

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

int height(struct node *root){
    if(root==NULL){
        return -1;
    }
    else{
        int leftHeight=height(root->lft);
        int rightHeight=height(root->rgt);
        return 1 + (leftHeight>=rightHeight?leftHeight:rightHeight);//using ternary operator
    }

}

int leafNodes(struct node *root){
    if(root == NULL) {
        return 0;
    }
    if(root->lft == NULL && root->rgt == NULL) {
        return 1;
    } else {
        int leftLeaf = leafNodes(root->lft);
        int rightLeaf = leafNodes(root->rgt);
        return leftLeaf + rightLeaf;
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
    printf("\nHeight of tree is %d.\n",height(root));
    int n=leafNodes(root);
    printf("\nThere are %d leaf nodes in the tree.\n",n);
    return 0;
}