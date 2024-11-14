#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void info() {
    time_t t;
    time(&t);
    printf("DIPESH KUMAR\nBT23CSH043\n\n%s\n", ctime(&t));
    return;
}

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteOdd() {
    struct Node* temp = head, *prev;
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            if (temp == head) {
                head = temp->next;
                free(temp);
                temp = head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void display() {
    struct Node* temp = head;
    if (head == NULL)
        printf("List is empty\n");
    else {
        printf("List: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    info();
    insert(1);
    insert(3);
    insert(2);
    insert(5);
    insert(4);
    display();
    deleteOdd();
    display();
    return 0;
}