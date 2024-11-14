// implement queue (enQueue,deQueue,display) using link list

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void info(){
    time_t t;
	time(&t);
	printf("DIPESH KUMAR\nBT23CSH043\n\n%s\n",ctime(&t));
	return;
}

struct queue{
    int data;
    struct queue *link;
}*front=NULL,*rear=NULL;

int isEmpty(){
    if(front==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void enQueue(int el){
    struct queue *temp=malloc(sizeof(struct queue));
    temp->data=el;
    temp->link=NULL;
    if(isEmpty()){
        front=temp;
        rear=temp;
    }
    else{
        rear->link=temp;
        rear=temp;
    }
    return;    
}

int deQueue(){
    if(isEmpty()){
        printf("Underflow\n");
        return -1;
    }
    else{
        struct queue *temp=front;
        int x=front->data;
        if(front==rear){
            front==NULL;
            rear==NULL;
        }
        else{
            front=front->link;
        }
        free(temp);
        return x;
    }
}

void display(){
    if(isEmpty()){
        printf("\nEmpty Queue\n");
    }
    else{
        printf("\n");
        struct queue *temp=front;
        while(temp!=rear->link){
            printf("%d\t",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
    return;
}

int main(){
    info();
    enQueue(20);
    enQueue(80);
    enQueue(90);
    display();
    printf("%d is dequeued element\n",deQueue());
    printf("%d is dequeued element\n",deQueue());
    enQueue(900);
    enQueue(890);
    enQueue(-9870);
    display();

    return 0;
}



