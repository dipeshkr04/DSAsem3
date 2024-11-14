#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *insert(Node **hd, int size, char s[])
{
    for (int i = 0; i < size; i++)
    {
        int d = s[i] - '0';
        Node *ptr = malloc(sizeof(Node));
        ptr->data = d;
        ptr->next = NULL;
        if (*hd == NULL)
        {
            *hd = ptr;
        }
        else
        {
            ptr->next = *hd;
            *hd = ptr;
        }
    }
    return *hd;
}

Node *Addition(Node **hd1, Node **hd2, Node **hd)
{
    Node *p1 = *hd1;
    Node *p2 = *hd2;
    int c = 0;

    while (p1 != NULL || p2 != NULL || c > 0)
    {
        int sum = c;
        
        if (p1 != NULL)
        {
            sum += p1->data;
            p1 = p1->next;
        }
        if (p2 != NULL)
        {
            sum += p2->data;
            p2 = p2->next;
        }

        Node *ptr = malloc(sizeof(Node));
        ptr->data = sum % 10;
        c = sum / 10;
        ptr->next = NULL;

        if (*hd == NULL)
        {
            *hd = ptr;
        }
        else
        {
            ptr->next = *hd;
            *hd = ptr;
        }
    }

    return *hd;
}

void display(Node *hd)
{
    Node *temp = hd;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    unsigned long long n1, n2;
    printf("Enter Number of digits in 1st number:");
    scanf("%llu", &n1);
    printf("Enter Number of digits in 2nd number:");
    scanf("%llu", &n2);
    char s1[n1 + 1], s2[n2 + 1];
    printf("Enter First Number:");
    scanf("%s", s1);
    printf("Enter Second Number:");
    scanf("%s", s2);

    Node *head1 = NULL;
    Node *head2 = NULL;

    head1 = insert(&head1, n1, s1);
    head2 = insert(&head2, n2, s2);

    Node *head = NULL;
    head = Addition(&head1, &head2, &head);

    printf("Addition of two numbers: ");
    display(head);
    printf("\n");

    return 0;
}
