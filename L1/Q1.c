#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int degree;
    struct node *next;
};

struct node* polynomial(struct node *head, int coeff, int degree) {
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr->coeff = coeff;
    ptr->degree = degree;
    ptr->next = head;
    head = ptr;
    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("Coefficient: %d, Degree: %d\n", temp->coeff, temp->degree);
        temp = temp->next;
    }
}

struct node *addition(struct node *head, struct node *h1, struct node *h2){
    struct node *p=h1;
    struct node *q=h2;
    while(p!=NULL && q!=NULL){
        struct node *temp=head;
        struct node *ptr=(struct node*)malloc(sizeof(struct node));
        if((p!=NULL && q!=NULL) && (p->degree > q->degree)){
            ptr->degree=p->degree;
            ptr->coeff=p->coeff;
            ptr->next=NULL;
            if(head==NULL){
                head=ptr;
            }
            else{
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=ptr;
            }
            p=p->next;
        }
        else if((p!=NULL && q!=NULL) && (p->degree < q->degree)){
            ptr->degree=q->degree;
            ptr->coeff=q->coeff;
            ptr->next=NULL;
            if(head==NULL){
                head=ptr;
            }
            else{
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=ptr;
            }
            q=q->next;
        }
        else if((p!=NULL && q!=NULL) && (p->degree == q->degree)){
            ptr->degree=q->degree;
            ptr->coeff=q->coeff+p->coeff;
            ptr->next=NULL;
            if(head==NULL){
                head=ptr;
            }
            else{
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=ptr;
            }
            q=q->next;
            p=p->next;
        }
        else if(p==NULL && q!=NULL){
                ptr->coeff=q->coeff;
                ptr->degree=q->degree;
                ptr->next=NULL;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=ptr;
                q=q->next;
            
        }
        else if(q==NULL && p!=NULL){
                ptr->coeff=p->coeff;
                ptr->degree=p->degree;
                ptr->next=NULL;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=ptr;
                p=p->next;
        }

    }
    return head;
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n1, n2;

    printf("Enter Number of terms in polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter Number of terms in polynomial 2: ");
    scanf("%d", &n2);

    int i;
    printf("Enter the following details of 1st polynommial in ascending order of degree of x\n");
    for (i = 0; i < n1; i++) {
        int co, de;
        printf("Enter Degree: ");
        scanf("%d", &de);
        printf("Enter Coefficient: ");
        scanf("%d", &co);
        head1 = polynomial(head1, co, de);
    }
    printf("Enter the following details of 2nd polynommial in ascending order of degree of x\n");
    for (i = 0; i < n2; i++) {
        int co, de;
        printf("Enter Degree: ");
        scanf("%d", &de);
        printf("Enter Coefficient: ");
        scanf("%d", &co);
        head2 = polynomial(head2, co, de);
    }

    printf("Polynomial 1:\n");
    display(head1);
    printf("Polynomial 2:\n");
    display(head2);
    struct node *head3=NULL;
    head3=addition(head3,head1,head2);
    printf("Sum of the two polynomial is:\n");
    display(head3); 
    return 0;
}