//Create a menu driven program to create a binary search tree and perform following operation on it Traverse,Insert

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
    while(1){
        int n;
        printf("\nEnter 1 to insert new node...\nEnter 2 to print tree in Pre Order...\nEnter 3 to print tree in In Order...\nEnter 4 to print tree in Post Order...\nEnter any other to exit program...\n");
        scanf("%d",&n);
        int t;
        switch(n){
            case 1:
                printf("Enter data for new node...");
                scanf("%d",&t);
                root=binaryTreeInsert(root,t);
                break;
            case 2:
                printf("\nPre Order :-\t");
                preOrder(root);
                break;
            case 3:
                printf("\nIn Order :-\t");
                inOrder(root);
                break;            
            case 4:
                printf("\nPost Order :-\t");
                postOrder(root);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}