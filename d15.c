#include<stdio.h>//INSERSTION IN CIRCULAR LINKED LIST.
#include<stdlib.h>
struct node
{ 
    int data;
    struct node *next;
    }*tail;
int create(struct node **tail)
{
    int choice=1;
    struct node *newnode;
    while(choice)
    {   
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(*tail==NULL)
        {
            *tail=newnode;
            newnode->next=newnode;
        }
        else
        {
            newnode->next=(*tail)->next;
            (*tail)->next=newnode;
            *tail=newnode;
        }
        printf("if you want to continue press 1 or Exit press 0 :");
        scanf("%d",&choice);
    }
    return 0;
}
int inserting_node_fornt(struct node **tail)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data to newnode at front: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(*tail==NULL)
    {
        *tail=newnode;
        newnode->next=newnode;
    }
    else
    {
        newnode->next=(*tail)->next;
        (*tail)->next=newnode;
    }
}
int inserting_node_end(struct node **tail)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data to newnode at end: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(*tail==NULL)
    {
        *tail=newnode;
        newnode->next=newnode;
    }
    else
    {
        newnode->next=(*tail)->next;
        (*tail)->next=newnode;
        *tail=newnode;
    }
}
int length_of_CLL(struct node **tail)
{
    int count=1;
    struct node *temp;
    temp=(*tail)->next;
    while(temp->next!=(*tail)->next)
    {
        count++;
        temp=temp->next;
    }
    printf("Length is :%d.\n",count);
}
int insert_at_given_postion(struct node **tail,int pos)
{
    int i=1 ,l;
    struct node *newnode,*temp;
    printf("Enter the position you want to insert.\n");
    scanf("%d",&pos);
    l=length_of_CLL(tail);
    if(pos<0||pos>l)
    {
        printf("Invalid position.\n");
    }
    else if(pos==1)
    {
        inserting_node_fornt(tail);
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data to given position: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp=(*tail)->next;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
int display(struct node *tail)
{
    if(tail==NULL)
    {
        printf("not having a any node .\n");
    }
    else
    {
        struct node *temp=tail->next;
        while(temp->next!=tail->next)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
        return 0;
    }
}
int main()
{
    int pos;
    struct node *tail=NULL;
    create(&tail);
    inserting_node_fornt(&tail);
    inserting_node_end(&tail);
    insert_at_given_postion(&tail,pos);
    length_of_CLL(&tail);
    display(tail);
    return 0;
}
