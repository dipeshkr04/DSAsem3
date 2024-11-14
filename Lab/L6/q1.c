// insert and del operation on singly,doubly, singly circular, doubly circular
// Create a doubly linked list by inserting nodes at the beginning.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void info(){
	time_t t;
	time(&t);
	printf("Harshit Srivastava\nBT23CSH051\n\n%s\n",ctime(&t));
	return;
}

struct node{
    struct node *pre;
    int data;
    struct node *next;
};

struct node *ins_end(struct node *head, int item){
    struct node *temp=head;
    struct node *ptr=malloc(sizeof(struct node));
    if(head==NULL){
        ptr->data = item;
        ptr->pre=NULL;
        ptr->next=NULL;
        head = temp;
        return head;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ptr->data=item;
    ptr->pre=temp;
    ptr->next=NULL;
    temp->next=ptr;
    return head;

}

void display(struct node *head){
    if(head==NULL){
        printf("Enterd linked list is empty.");
        return;
    }
    struct node *temp=head;
    do{
        printf("%d\t",temp->data);
        temp = temp->next;
    }while(temp!=NULL);
    printf("\n");
    return;
}

int main (){

    info();

    int n;
    printf("Enter number of nodes...");
    scanf("%d",&n);

    struct node *head=malloc(sizeof(struct node));

    for(int w=0;w<n;w++){
        int item;
        printf("Enter node data...");
        scanf("%d",&item);
        head = ins_end(head,item);
    }
    printf("Enterd linkedlist :\n");
    display(head);

    return 0;
}
