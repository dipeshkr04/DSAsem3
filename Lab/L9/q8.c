// 8)function to print all ancestor of any node

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

// int height(struct node *root){
//     if(root==NULL){
//         return -1;
//     }
//     else{
//         int leftHeight=height(root->lft);
//         int rightHeight=height(root->rgt);
//         return 1 + (leftHeight>=rightHeight?leftHeight:rightHeight);//using ternary operator
//     }

// }

// int leafNodes(struct node *root){
//     if(root == NULL) {
//         return 0;
//     }
//     if(root->lft == NULL && root->rgt == NULL) {
//         return 1;
//     } else {
//         int leftLeaf = leafNodes(root->lft);
//         int rightLeaf = leafNodes(root->rgt);
//         return leftLeaf + rightLeaf;
//     }
// }

struct node* targetNode(struct node *root, int el){
    if(root==NULL){
        return NULL;
    }
    else if(root->data==el){
        return root;
    }
    else{
        struct node *left=targetNode(root->lft,el);
        if(left != NULL){
            return left;
        }
        struct node *right=targetNode(root->rgt,el);
        return right;
    }
}

// int degree(struct node *root, int el){
//     struct node *temp = targetNode(root,el);
//     if(temp == NULL){
//         printf("\nTarget node not found.\n");
//         return -1;
//     }
//     else if(temp->lft == NULL && temp->rgt == NULL){
//         return 0;
//     }
//     else if(temp->lft != NULL && temp->rgt != NULL){
//         return 2; 
//     }
//     else {
//         return 1;
//     }
// }


int depth(struct node *root, int el){
    if(root==NULL){
        return -1;
    }
    int dist=-1;
    if(root->data==el || (dist=depth(root->lft,el))>=0 || (dist=depth(root->rgt,el))>=0){
            return dist+1;
    }
    return dist;
}

// int nodeHeight(struct node *root, int el){
//     struct node *temp = targetNode(root,el);
//     return height(temp);
// }

// void descendents(struct node *root, int el){
//     struct node *temp = targetNode(root,el);
//     printf("\nDescendents of node having data %d : - ");
//     inOrder(root->lft);
//     inOrder(root->rgt);
// }

void ancestors(struct node *root, int el, int A[], int n){
    if (root == NULL){
       return;
    } 
    else if(root->data == el){
        if (n == 0) {
            printf("\nEntered node is root node of tree.");
        } 
        else{
            printf("\nAncestors are: ");
            for (int i = 0; i < n; i++) {
                printf("%d\t", A[i]);
            }
        }
        return;
    }
    else if(n <= 0){
        return;
    } 
    else{
        A[n-1] = root->data;
        ancestors(root->lft, el, A, n - 1);
        ancestors(root->rgt, el, A, n - 1);
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
    // printf("\nHeight of tree is %d.",height(root));
    // int n=leafNodes(root);
    // printf("\nThere are %d leaf nodes in the tree.",n);
    // int x;
    // printf("\nEnter the node's data whose degree is to be found...");
    // scanf("%d",&x);
    // int y=degree(root,x);
    // printf("\nDegree of the node having data %d is %d",x,y);
    // printf("\nEnter the number whose depth has to be find...");
    // int a;
    // scanf("%d",&a);
    // int b=depth(root,a);
    // printf("\nDepth of %d is %d.",a,b);
    // int l;
    // printf("\nEnter the node's data whose height is to be find...");
    // scanf("%d",&l);
    // int m=nodeHeight(root,l);
    // printf("\nHeight of %d is %d.",l,m);
    // int e;
    // printf("\nEnter node's data whose descendent's has to be printed...");
    // scanf("%d",&e);
    // descendents(root,e);
    int t;
    printf("\nEnter node data whose ancestor's have to be found...");
    scanf("%d",&t);
    struct node *temp=targetNode(root,t);
    if(temp!=NULL){
        int depthNode = depth(root,t);
        int A[depthNode+1];
        ancestors(root,t,A,depthNode+1);
    }
    else{
        printf("\nEntered node is not presebt in the tree.");
    }
    return 0;
}