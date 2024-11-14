// 2 create a linklist by inserting a node at the specified position of the linklist

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
    struct node* link;
};

void output(struct node *temp){
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
    return;
}

struct node* insert_pos(struct node *head, int item, int pos){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=item;
    ptr->link=NULL;
    if(pos<1){
        printf("Enter valid position...\n");
    }
    else if(pos==1 && head==NULL){
        head=ptr;
    }
    else if(pos==1){
        ptr->link=head;
        head=ptr;
    }
    else{
        int x=1;
        struct node *temp=head;
        while(x!=pos-1 && temp->link!=NULL){
            temp=temp->link;
            x++;
        }
        ptr->link=temp->link;
        temp->link=ptr;
    }
    return head;
}

int main (){
    info();
    struct node *head=NULL;int n;
    printf("Enter number of nodes...");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int item;
        int pos;
        printf("Enter positon...");
        scanf("%d",&pos);
        printf("Enter data for node %d...",pos);
        scanf("%d",&item);
        head = insert_pos(head,item,pos);
    }
    printf("Entered linked list...\n");
    output(head);
    return 0;
}
