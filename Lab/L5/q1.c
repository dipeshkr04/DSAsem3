#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void info()
{
    time_t t;
    time(&t);
    printf("DIPESH KUMAR\nBT23CSH043\n\n%s\n", ctime(&t));
    return;
}

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void splitList(struct Node *head, struct Node **even_head_ref, struct Node **odd_head_ref)
{
    struct Node *even_tail = NULL;
    struct Node *odd_tail = NULL;

    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            if (*even_head_ref == NULL)
            {
                *even_head_ref = head;
                even_tail = head;
            }
            else
            {
                even_tail->next = head;
                even_tail = even_tail->next;
            }
        }
        else
        {
            if (*odd_head_ref == NULL)
            {
                *odd_head_ref = head;
                odd_tail = head;
            }
            else
            {
                odd_tail->next = head;
                odd_tail = odd_tail->next;
            }
        }
        head = head->next;
    }

    if (even_tail != NULL)
        even_tail->next = NULL;
    if (odd_tail != NULL)
        odd_tail->next = NULL;
}

struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct Node *mergeSortedLists(struct Node *even_head, struct Node *odd_head)
{
    struct Node *result = NULL;
    struct Node *tail = NULL;

    while (even_head != NULL && odd_head != NULL)
    {
        if (even_head->data <= odd_head->data)
        {
            if (result == NULL)
            {
                result = even_head;
                tail = even_head;
            }
            else
            {
                tail->next = even_head;
                tail = tail->next;
            }
            even_head = even_head->next;
        }
        else
        {
            if (result == NULL)
            {
                result = odd_head;
                tail = odd_head;
            }
            else
            {
                tail->next = odd_head;
                tail = tail->next;
            }
            odd_head = odd_head->next;
        }
    }

    if (even_head != NULL)
    {
        tail->next = even_head;
    }
    else if (odd_head != NULL)
    {
        tail->next = odd_head;
    }

    return result;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sortLinkedList(struct Node **head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    struct Node *even_head = NULL;
    struct Node *odd_head = NULL;

    splitList(*head_ref, &even_head, &odd_head);

    struct Node *sorted_even_head = NULL;
    struct Node *curr = even_head;

    while (curr != NULL)
    {
        struct Node *next = curr->next;
        if (sorted_even_head == NULL || curr->data <= sorted_even_head->data)
        {
            curr->next = sorted_even_head;
            sorted_even_head = curr;
        }
        else
        {
            struct Node *temp = sorted_even_head;
            while (temp->next != NULL && temp->next->data < curr->data)
            {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }

    odd_head = reverseList(odd_head);

    *head_ref = mergeSortedLists(sorted_even_head, odd_head);
}

int main()
{
    info();
    struct Node *head = NULL;
    insert(&head, 17);
    insert(&head, 15);
    insert(&head, 8);
    insert(&head, 12);
    insert(&head, 10);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 1);

    printf("Original list: \n");
    printList(head);

    sortLinkedList(&head);

    printf("Sorted list with even numbers in increasing order and odd numbers in decreasing order: \n");
    printList(head);

    return 0;
}

