// Write a program to delete a node at specific position.

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

struct node *del_p(struct node *head, int p){
    struct node *ptr= head;
    int n=1;
    while(ptr->link!=NULL){
        ptr=ptr->link;
        n++;
    }
	if(head==NULL){
		printf("Empty linked list.");
	}
    else if(p>n){
        printf("Short link list");
    }
    else{
        int i=1;
        struct node *temp=head, *pre=NULL;
        while(i<p){
            pre=temp;
            temp=temp->link;
            i++;
        }
        pre->link=temp->link;
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

    printf("Enter position at of node to be deleted...");
    int p;
    scanf("%d",&p);
    head=del_p(head,p);
    printf("Linked list after deletion of %d node...\n",p);
    output(head);
    return 0;
}
