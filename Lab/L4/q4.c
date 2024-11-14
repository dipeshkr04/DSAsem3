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
    temp->data=item;
    temp->link=NULL;

    if(head == NULL){
        head = temp;
    }
    else{
        temp->link = head;
        head = temp;
    }
    return head;
}

void output(struct node *temp){
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->link;
    }
    printf("\n");
    return;
}

void del_d(struct node *head){
    struct node *ptr, *ptr2, *dup;
    ptr = head;

    while(ptr != NULL && ptr->link != NULL){
        ptr2 = ptr;

        while(ptr2->link != NULL){
            if(ptr->data == ptr2->link->data){
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(dup);
            }
            else{
                ptr2 = ptr2->link;
            }
        }
        ptr = ptr->link;
    }
}

int main (){
    info();
    struct node *head = NULL;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        printf("Enter data: ");
        int item;
        scanf("%d",&item);
        head = input(head, item);
    }
    printf("Entered linked list:\n");
    output(head);

    del_d(head);
    printf("Linked list after deletion of duplicate nodes:\n");
    output(head);
    return 0;
}