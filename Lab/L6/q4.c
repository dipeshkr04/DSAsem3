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
void duplicate() {
struct Node* temp = head;
while (temp != NULL) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = temp->data;
newNode->next = temp->next;
temp->next = newNode;
temp = newNode->next;
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
insert(10);
insert(20);
insert(30);
insert(40);
insert(50);
display();
duplicate();
display();
return 0;
}