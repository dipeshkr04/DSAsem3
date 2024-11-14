#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
    struct node *prev;
} *head = NULL, *current = NULL;

void display()
{
    struct node *temp = head;
    while (temp!= NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

void insert_queue()
{
    int n;
    printf("Enter Size of queue: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int d, p;
        printf("Enter Number: ");
        scanf("%d", &d);
        printf("Enter priority: ");
        scanf("%d", &p);

        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = d;
        ptr->priority = p;
        ptr->next = NULL;
        ptr->prev = NULL;

        if (head == NULL)
        {
            head = ptr;
            current = ptr;
        }
        else
        {
            if (p <= current->priority)
            {
                while (current->prev != NULL && current->priority >= p)
                {
                    current = current->prev;
                }
            }
            else
            {
                while (current->next != NULL && current->priority < p)
                {
                    current = current->next;
                }
            }

            if (p <= current->priority)
            {
                if (current == head)
                {
                    ptr->next = head;
                    head->prev = ptr;
                    head = ptr;
                }
                else
                {
                    ptr->next = current;
                    ptr->prev = current->prev;
                    current->prev->next = ptr;
                    current->prev = ptr;
                }
            }
            else
            {
                ptr->prev = current;
                ptr->next = current->next;
                if (current->next != NULL)
                {
                    current->next->prev = ptr;
                }
                current->next = ptr;
            }

            current = ptr;
        }
    }
}

int main()
{
    insert_queue();
    display();
    return 0;
}