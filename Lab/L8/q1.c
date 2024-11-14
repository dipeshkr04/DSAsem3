/*
Implement a stack using linked list, display it, pop elements 
if odd add in a doubly linked list else in a singly circular
linked list display them and them and then sort them.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void info(){
    time_t t;
    time(&t);
    printf("DIPESH KUMAR\nBT23CSH043\n\n%s\n",ctime(&t));
    return;
}

struct stack{
    int data;
    struct stack *link;
}*top=NULL;

struct nodeCir{
    int data;
    struct nodeCir *link;
}*tail=NULL;

struct nodeDll{
    struct nodeDll *pre;
    int data;
    struct nodeDll *nxt;
}*head=NULL;

void addCir(int el){
    struct nodeCir *temp=malloc(sizeof(struct nodeCir));
    if(temp==NULL){
        printf("Stack Overflow\n");
        return;
    }
    temp->data = el;
    temp->link = NULL;
    if(tail == NULL) {
        tail = temp;
        tail->link = temp;
    }
    else {
        temp->link=tail->link;
        tail->link = temp;
        tail=temp;
    }
    return;
}

void displayCir(){
    if(tail == NULL) {
        printf("\nCircular linked list Underflow\n"); 
        return ;  
    }
    struct nodeCir *temp=tail->link;
    do{
        printf("%d\t",temp->data);
        temp=temp->link;
    }while(temp!=tail->link);
    printf("\n");
    return;
}

void displayDll(){
    if(head == NULL) {
        printf("\n Doubly Linked List Underflow\n");  
        return;   
    }
    struct nodeDll *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->nxt;
    }
    printf("\n");
    return;
}

void addDll(int el){
    struct nodeDll *temp=malloc(sizeof(struct nodeDll));
    if(temp==NULL){
        printf("Stack Overflow\n");
        return;
    }
    temp->data = el;
    temp->pre = NULL;
    temp->nxt = NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        temp->nxt=head;
        head->pre=temp;
        head=temp; 
    }
    return;
}

void displayStack(){
    if(top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    struct stack *temp=top;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
    return;
}

void push(int el){
    struct stack *temp=malloc(sizeof(struct stack));
    if(temp==NULL){
        printf("Stack Overflow\n");
        exit(0);
    }
    temp->data=el;
    temp->link=top;
    top=temp;
    return;
}

void pop(){
    if(top==NULL){
        printf("Stack Underflow\n");
        return ;
    }
    else{
        while(top!=NULL){
            struct stack *temp=top;
            top = top -> link;
            int x = temp->data;
            free(temp);
            printf("%d is popped from Stack \n",x);
            if(x%2==0){
                addCir(x);
            }
            else{
                addDll(x);
            }
        }
    }
    return;
}

void sortCir(){
    struct nodeCir *temp=NULL;
    struct nodeCir *ptr=NULL;
    for(temp=tail->link; temp != tail; temp=temp->link){
        for(ptr=temp->link; ptr != tail->link; ptr=ptr->link){
            if(temp->data > ptr->data){
                int a = temp->data;
                temp->data = ptr->data;
                ptr->data = a;
            }
        }
    }
    // One more iteration for the last element
    for(ptr=temp->link; ptr != tail->link; ptr=ptr->link){
        if(temp->data > ptr->data){
            int a = temp->data;
            temp->data = ptr->data;
            ptr->data = a;
        }
    }
    return;
}

void sortDll(){
    struct nodeDll *temp=NULL;
    struct nodeDll *ptr=NULL;
    for(temp=head; temp!=NULL; temp=temp->nxt){
        for(ptr=temp->nxt; ptr!=NULL; ptr=ptr->nxt){
            if(ptr->data < temp->data){
                int a=temp->data;
                temp->data=ptr->data;
                ptr->data=a;
            }
        }
    }
    return;
}

int main(){
    info();
    printf("\n");
    int n;
    printf("Enter number of elements in stack: ");
    scanf("%d",&n);
    printf("Enter %d elements in stack: \n",n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        push(a);
    }
    printf("Entered stack is: \n");
    displayStack();
    pop();
    printf("\n Circular linked list is: \n");
    displayCir();
    printf("\n Doubly linked list is: \n");
    displayDll();
    sortCir();
    sortDll();
    printf("\n Sorted circular linked list is: \n");
    displayCir();
    printf("\n Sorted doubly linked list is: \n");
    displayDll();
    return 0;
}