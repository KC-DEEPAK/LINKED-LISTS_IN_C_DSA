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
void delete_at_front()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Invalid Node ");
    }
    else if(head->next==head)
    {
        head=tail=NULL;
        free(temp);
    }
    else
    {
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}
void delete_at_end()
{
    struct node *temp=tail;
    if(head==NULL)
    {
        printf("Invalid or Empty");

    }
    else if(head->next==head)
    {
        head=tail=NULL;
        free(temp);
    }
    else
    {
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
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
void delete_node_giveposition()
{
    struct node *temp=head;
    int i=1,pos,l;
    printf("Enter the node you want to delete: ");
    scanf("%d",&pos);
    l=get_length();
    if(pos<1 || pos>l)
    {
        printf("EMPTY");
    }
    else if(pos==1)
    {
        delete_at_front();
    }
    else
    {
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        if(temp->next==head)
        {
            tail=temp->prev;
        }
        free(temp);
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
    display();
    printf("\n=== BEFORE DELETE A NODE === .\n");
    printf("\n=== AFTER DELETE A NODE FROM FRONT === .\n");
    delete_at_front();
    display();
    printf("\n=== AFTER DELETE A NODE FROM END === .\n");
    delete_at_end();
    display();
    printf("\n=== AFTER DELETE A NODE FROM GIVEN POSITION === .\n");
    delete_node_giveposition();
    display();
    return 0;
}