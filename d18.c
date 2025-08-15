#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head,*tail;
void create()
{
    int choice=1;
    struct node *newnode;
    head=NULL;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data to the node.\n");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        printf("Enter the 1 for Continue 0 for Exit :");
        scanf("%d",&choice);
    }
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Its Invalid list .\n");
    }
    else
    {
      while(temp!=tail)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);  
    }
}
int main()
{
    create();
    display();
    return 0;
}