#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int create(struct node **head)
{
    int choice = 1;
    struct node *temp = NULL;

    while (choice)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data for node:\n");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if (*head == NULL)
        {
            *head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Do you want to continue? Press 1 for Yes, 0 for No:\n");
        scanf("%d", &choice);
    }

    return 0;
}

int display(struct node *head)
{
    struct node *temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

int main()
{
    struct node *head = NULL;
    create(&head);
    display(head);
    return 0;
}
