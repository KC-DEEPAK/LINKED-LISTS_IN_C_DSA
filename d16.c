#include<stdio.h>//DELETING A NODE FROM  CIRCULAR LINKED LIST.
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
int delete_at_front(struct node **tail)
{
    struct node *temp;
    temp=(*tail)->next;
    if(*tail==NULL)
    {
        printf("NO nodes are present .\n");
    }
    else if(temp->next==temp)
    {
        tail=0;
        free(temp);
    }
    else
    {
        (*tail)->next=temp->next;
        free(temp);
    }
    return 0;
}
int deleting_node_at_end(struct node **tail)
{
    struct node *current,*prev;
    current=(*tail)->next;
    if(*tail==NULL)
    {
        printf("its No node present in the List ");
    }
    else if(current->next==current)
    {
        tail=NULL;
        free(current);
    }
    else
    {
        while(current->next!=(*tail)->next)
        {
            prev=current;
            current=current->next;
        }
        prev->next=(*tail)->next;
        *tail=prev;
        free(current);
    }
    return 0;
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
int delete_node_at_position(struct node **tail,int pos)
{
    int i=1,l;
    struct node *current,*nextnode;
    current=(*tail)->next;
    printf("enter the position you want to delete the node :");
    scanf("%d",&pos);
    l= length_of_CLL(tail);
    if(pos<1||pos>l)
    {
        printf("position not found.\n");
    }
    else if(pos==1)
    {
        delete_at_front(tail);
    }
    else
    {
        while(i<pos-1)
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(current);
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
int main() {
    struct node *tail = NULL;
    int pos;
    printf("=== Circular Linked List Program ===\n");
    printf("\nCreating the list...\n");
    create(&tail);
    printf("\nList after creation:\n");
    display(tail);
    printf("\nDeleting a node from the front...\n");
    delete_at_front(&tail);
    printf("List after deleting from front:\n");
    display(tail);
    printf("\nDeleting a node from the end...\n");
    deleting_node_at_end(&tail);
    printf("List after deleting from end:\n");
    display(tail);
    printf("\nDeleting a node from given position...\n");
    delete_node_at_position(&tail,pos);
    printf("List after deleting from given position.\n");
    display(tail);
    printf("\n=== Program Finished ===\n");
    return 0;
}