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
void delete(int value) {
struct Node* temp = head, *prev;
if (temp != NULL && temp->data == value) {
while (temp->next != head)
temp = temp->next;
temp->next = head->next;
free(head);
head = temp->next;
} else {
while (temp->next != NULL && temp->next->data != value) {
prev = temp;
temp = temp->next;
}
if (temp->next == NULL)
printf("Element not found\n");
else {
prev->next = temp->next;
free(temp);
}
}
}
void display() {
struct Node* temp = head;
if (head == NULL)
printf("List is empty\n");
else {
printf("List: ");
while (temp->next != head) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("%d\n", temp->data);
}
}
int main() {
info();
insert(10);
insert(20);
insert(30);
display();
delete(20);
display();
return 0;
}
