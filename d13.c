#include<stdio.h>
#include<stdlib.h>
struct node
{ 
    int data;
    struct node *next;
    }*head;
int create(struct node **head)
{
    int choice=1;
    struct node *newnode,*temp=NULL;
    *head=NULL;
    while(choice)
    {   
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(*head==NULL)
        {
            *head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=*head;
        printf("if you want to continue press 1 or Exit press 0 :");
        scanf("%d",&choice);
    }
    return 0;
}
int display(struct node *head)
{
    struct node *temp=head;
    while(temp->next!=head)
    {
        printf("circular list is : %d\n",temp->data);
        temp=temp->next;
    }
    printf("circular list is : 2%d\n",temp->data);
    return 0;
}
int main()
{
    struct node *head=NULL;
    create(&head);
    display(head);
    return 0;
}