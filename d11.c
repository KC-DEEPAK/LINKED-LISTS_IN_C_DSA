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
    int choice=1;
    struct node *temp=NULL;
    while(choice)
    {
        struct node *newnode=(struct node*) malloc(sizeof(struct node));
        printf("enter the data to node.\n");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(*head==NULL)
        {
            *head = temp = newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        printf("doyou want to continue press 1 or not press 0.\n");
        scanf("%d",&choice);

    }   
    return 0;
}
void reverse(struct node **head, struct node **tail) {
    struct node *current = *head;
    struct node *temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *tail = *head;    
        *head = temp->prev; 
    }
}
int display(struct node **head)
{
    struct node *temp=*head;
    printf("Doubly linked list.\n");
    while(temp!=NULL)
    {
    printf("%d", temp->data);
    temp=temp->next;
    }
    printf("\n");
    return 0;
}
int main()
{

    struct node *head=NULL;
    struct node *tail=NULL;
    create(&head);
    printf("Before reversing a DLL.\n");
    display(&head);
    reverse(&head,&tail);
    printf("After reversing a DLL.\n");
    display(&head);
    return 0;
}
    
