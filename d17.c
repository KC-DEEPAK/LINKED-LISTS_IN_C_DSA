#include<stdio.h>//REVERSING  A CIRCULAR LINKED LIST.
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
int reverse_CL(struct node **tail)
{
    struct node *prev,*current,*nextnode;
    current=(*tail)->next;
    nextnode=current->next;
    if(tail==NULL)
    {
        printf("Empty List.\n");
    }
    else if(current->next==current)
    {
        printf("Only one node is present.\n");
    }
    else
    {
        while(current!=*tail)
        {
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
        }
        nextnode->next=*tail;
        *tail=nextnode;
    }
}
int display(struct node *tail)
{
    if(tail==NULL)
    {
        printf("not having a any node .\n");
    }
    struct node *temp=tail->next;
    while(temp->next!=tail->next)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    return 0;
}
int main()
{
    struct node *tail=NULL;
    printf("\n ==== Create a Circular List ==== \n");
    create(&tail);
    display(tail);
    printf("\n ====Before Reversing a List.====\n");
    reverse_CL(&tail);
    display(tail);
    printf("\n====After the Reversing a NOde.====\n");
    return 0;
}
