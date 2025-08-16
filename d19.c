#include<stdio.h>//INSERTING A  NODE TO DCLL
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
void insert_front()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data at Front:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;
    }
}
int get_length()
{
    int count=1;
    struct node *temp;
    temp=head;
    while(temp!=tail)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void insert_at_given_pos()
{
    struct node *newnode;
    struct node *temp=head;
    int pos,i=1;
    printf("Enter the position you want to insert a node: ");
    scanf("%d",&pos);
    int l=get_length();
    if(pos<1 || pos>l)
    {
        printf("Invalid node \n");
    }
    else if(pos==1)
    {
        insert_front();
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the node value to  the given position : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
}
void insert_end()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data at END:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
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
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);  
    }
}
int main()
{
    create();
    insert_front();
    insert_end();
    insert_at_given_pos();
    display();
    return 0;
}