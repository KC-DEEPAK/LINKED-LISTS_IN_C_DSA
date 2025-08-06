#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
int create(struct node **head,struct node **tail)
{
    int choice = 1;
    while (choice)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data for node:\n");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if (*head == NULL)
        {
            *head = *tail = newnode;
        }
        else
        {
            (*tail)->next = newnode;
            newnode->prev = (*tail);
            *tail = newnode;
        }

        printf("Do you want to continue? Press 1 for Yes, 0 for No:\n");
        scanf("%d", &choice);
    }

    return 0;
};
int delete_front(struct node **head,struct node **tail)
{
    if(*head==NULL)
    {
        printf("invaild or its empty");
        return -1;
    }
    else
    {
        struct node *temp=*head;
        if(*head==*tail)
        {
            *head=*tail=NULL;

        }
        else
        {
            *head=(*head)->next;
            (*head)->prev=NULL; 

        }
        free(temp);
        return 0;
    }
}
int delete_end(struct node **head,struct node **tail)
{
    if(*tail==NULL)
    {
        printf("invaild...");
        return -1;
    }
    else
    {
        struct node *temp=*tail;
        *tail=(*tail)->prev;
        (*tail)->next=NULL;
        free(temp);
    }

}
int delete_given_pos(struct node **head,struct node **tail,int pos)
{
    int i=1;
    struct node *temp;
    if(pos<0)
    {
        printf("invaild position");
        return -1;
    }

    else
    {
        temp=*head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }

}
int display(struct node *head)
{
    struct node *temp=head;
    printf("Doubly linked list.\n");
    while(temp!=NULL)
    {
    printf("%d",temp->data);
    temp=temp->next;
    }
    printf("\n");
    return 0;
}
int main()
{
    struct node *newnode;
    struct node *temp;
    struct node *head=NULL;
    struct node *tail=NULL;
    int pos;
    create(&head,&tail);

    printf("Before deleting .\n");
    display(head);

    printf("after deleting from front.\n");
    delete_front(&head,&tail);
    display(head);

    printf("after deleting from end.\n");
    delete_end(&head,&tail);
    display(head);

    printf("enter the position you want to delete.\n");
    scanf("%d",&pos);
    delete_given_pos(&head,&tail,pos);
    display(head);
    return 0;
}