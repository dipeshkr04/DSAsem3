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
struct Node* prev;
struct Node* next;
};
struct Node* head = NULL;
void insert(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
if (head == NULL) {
head = newNode;
head->prev = head;
head->next = head;
} else {
struct Node* temp = head->prev;
newNode->prev = temp;
newNode->next = head;
temp->next = newNode;
head->prev = newNode;
}
}
void delete(int value) {
struct Node* temp = head;
if (temp != NULL && temp->data == value) {
if (temp->next == temp) {
head = NULL;
free(temp);
} else {
struct Node* last = temp->prev;
last->next = temp->next;
temp->next->prev = last;
head = temp->next;
free(temp);
}
} else {
while (temp->next != head && temp->data != value)
temp = temp->next;
if (temp->data == value) {
struct Node* prev = temp->prev;
struct Node* next = temp->next;
prev->next = next;
next->prev = prev;
free(temp);
} else
printf("Element not found\n");
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