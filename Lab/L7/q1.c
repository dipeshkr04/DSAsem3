// impelement queue (enQueue,deQueue,display) using array

#include<stdio.h>
#include<time.h>
void info(){
    time_t t;
	time(&t);
	printf("DIPESH KUMAR\nBT23CSH043\n\n%s\n",ctime(&t));
	return;
}

#define MAX 20
int rear=-1,front=-1;
int A[MAX];

int isFull(){
    if(rear==MAX-1){
        return  1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enQueue(int el){
    if(isFull()){
        printf("Overflow\n");
    }
    else if(front==-1&&rear==-1){
        front++;
        A[++rear]=el;
    }
    else{
        A[++rear]=el;
    }
    return;    
}

int deQueue(){
    if(isEmpty()){
        printf("Underflow\n");
        return -1;
    }
    else{
        int x=A[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
        return x;
    }
}

void display(){
    if(isEmpty()){
        printf("\nEmpty Queue\n");
    }
    else{
        printf("\n");
        for(int i=front;i<=rear;i++){
            printf("%d\t",A[i]);
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
    display();

    return 0;
}