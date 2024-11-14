#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int val;
    struct node* left;
    struct node* right;
    int height;
}node;

node* root=NULL;

int getHeight(node* n){
    if(n==NULL)
        return 0;
    else
        return n->height;
}

node * createNode(int val){
    node*  newNode = (node*)malloc(sizeof(node));
    newNode->val  = val;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;

    
    return  newNode;
}

int getBalance(node* n){
    if(n==NULL)
        return 0;
    return  getHeight(n->left) - getHeight(n->right);
}

int max(int a, int b){
    if(a>=b)return a;
    
    else return b;
}

node*  rightRotate(node* y){
    node* x = y->left;
    node * T2 = x->right;
    x->right=y;
    y->left=T2;
    y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right),getHeight(x->left)) + 1;
    return x;
}

node*  leftRotate(node* x){
    node* y = x->right;
    node * T2 = y->left;
    y->left=x;
    x->right=T2;
    y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right),getHeight(x->left)) + 1;
    return y;
}

node* avl_insert(node* nd, int num){
    if(nd==NULL)
            return createNode(num);
    else if(num > nd->val)
        nd->right = avl_insert(nd->right,num);
    else if(num < nd->val)
        nd->left = avl_insert(nd->left,num);
    
    nd->height = 1 + max(getHeight(nd->left),getHeight(nd->right));
    int bf = getBalance(nd); 

    //LL
    if(bf>1 &&  num < nd->left->val){
        return rightRotate(nd);
    }
    //RR
    else if(bf<-1 &&  num > nd->right->val){
        return leftRotate(nd);
    }
    //LR
    else if(bf>1 && num > nd->left->val){
        nd->left = leftRotate(nd->left);
        return rightRotate(nd);
    }
    //RL   
    else if(bf<-1 && num < nd->right->val){
        nd->right = rightRotate(nd->right);
        return leftRotate(nd);
    }
    return nd;
}

void preorder(node * root){
    if(root!=NULL){
        printf("%d\t",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

node* avl_delete(node* root, int num){
    printf("\nDelete %d\n",num);
}


int main(){
    char str[] = "8i1i2i3i4i5i6d4d5";
    int count=str[0]-'0';
    for(int i=1; i < (2*count)+1 ; i+=2){
        if(str[i]=='i')
            root=avl_insert(root,str[i+1]-'0');
        else if(str[i]=='d')
            avl_delete(root,str[i+1]-'0');
    }
    preorder(root);
}