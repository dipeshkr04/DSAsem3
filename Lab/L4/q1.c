//wacp to delete 1st node of singly linked list

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
    struct node *temp=malloc(sizeof(struct node));
    temp->data=item;
    if(head==NULL){
        temp->link=NULL;
    }
    else{
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

struct node *del_i(struct node *head){
	if(head==NULL){
		printf("Empty linked list.\n");
	}
	else{
		struct node *temp=head;
		head=head->link;
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
    
    head=del_i(head);
    printf("Linked list after deletion of first node...\n");
    output(head);
    return 0;
}
