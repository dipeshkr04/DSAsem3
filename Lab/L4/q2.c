// Write a program to delete a node at the end.

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
    int data;
    struct node *link;
};

struct node* input(struct node *head, int item){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(head==NULL){
        temp->data=item;
        temp->link=NULL;
    }
    else{
    temp->data=item;
    temp->link=head;
    }
    return temp;
}

void output(struct node *temp){
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
    return;
}

struct node *del_e(struct node *head){
	if(head==NULL){
		printf("Empty linked list.");
	}
	else if(head->link==NULL){
	    free(head);
	    head=NULL;
	}
	else{
		struct node *temp=head;
        struct node *ptr=NULL;
        while(temp->link!=NULL){
            ptr=temp;
            temp=temp->link;
        }
		ptr->link=NULL;
		free(temp);
		temp=NULL;
	}
	return head;
}
int main (){

    info();
    struct node *head;
    int n;
    printf("Enter number of nodes...");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data...");
        int item;
        scanf("%d",&item);
        head=input(head,item);
    }
    printf("Enterd link list...\n");
    output(head);
    
    head=del_e(head);
    printf("Linked list after deletion of last node...\n");
    output(head);
    return 0;
}
