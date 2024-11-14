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
if (head == NULL) {
head = newNode;
newNode->next = head;
} else {
struct Node* temp = head;
while (temp->next != head)
temp = temp->next;
temp->next = newNode;
newNode->next = head;
}
}
void deleteOdd() {
struct Node* temp = head, *prev;
if (temp != NULL && temp->data % 2 != 0) {
while (temp->next != head)
temp = temp->next;
temp->next = head->next;
free(head);
head = temp->next;
} else {
while (temp->next != head) {
if (temp->next->data % 2 != 0) {
prev = temp;
temp = temp->next;
prev->next = temp->next;
free(temp);
temp = prev->next;
} else {
temp = temp->next;
}
}
}
}
void duplicateEven() {
struct Node* temp = head;
struct Node* newNode;
do {
if (temp->data % 2 == 0) {
newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = temp->data;
newNode->next = temp->next;
temp->next = newNode;
temp = newNode->next;
} else {
temp = temp->next;
}
} while (temp != head);
}
void display() {
struct Node* temp = head;
if (head == NULL)
printf("List is empty\n");
else {
printf("List: ");
do {
printf("%d ", temp->data);
temp = temp->next;
} while (temp != head);
printf("\n");
}
}
int main() {
info();
insert(10);
insert(20);
insert(30);
insert(40);
insert(50);
display();
deleteOdd();
display();
duplicateEven();
display();
return 0;
}