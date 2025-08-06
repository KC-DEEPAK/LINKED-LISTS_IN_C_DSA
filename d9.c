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
    struct node *tail = NULL;

    while (choice)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data for node:\n");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if (*head == NULL)
        {
            *head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        printf("Do you want to continue? Press 1 for Yes, 0 for No:\n");
        scanf("%d", &choice);
    }

    return 0;
};
int insert_fornt(struct node **head)
{
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    printf("enter the data at front node.\n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->prev=0;
    (*head)->prev=newnode;
    newnode->next=*head;
    *head=newnode;
    return 0;
}
int insert_end(struct node**head)
{
    struct node *tail;
    struct node *newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter the node at end .\n");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    return 0;
}
int insert_given_pos(struct node **head,int pos)
{
    int i=1;
    struct node *temp;
    if(pos==-1)
    {
        printf("its a invaid position .\n");
    }
    else if(pos==1)
    {
        struct node *head;
        insert_fornt(&head);
    }
    else
    {
        struct node *newnode=(struct node*) malloc(sizeof(struct node));
        temp=*head;
        printf("enter the data .\n");
        scanf("%d",&newnode->data);
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }

}
int insert_after_given_pos(struct node **head,int pos)
{
    int i=1;
    struct node *temp;
    if(pos==-1)
    {
        printf("its a invaid position .\n");
    }
    else
    {
        struct node *newnode=(struct node*) malloc(sizeof(struct node));
        temp=*head;
        printf("enter the data .\n");
        scanf("%d",&newnode->data);
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }

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
    int pos;
    struct node *head = NULL;
    create(&head);
    insert_fornt(&head);
    insert_end(&head);
    printf("enter the position you want to insert.\n");
    scanf("%d",&pos);
    insert_given_pos(&head,pos);
    printf("enter the position you want to insert after the given position.\n");
    scanf("%d",&pos);
    insert_after_given_pos(&head,pos);
    display(head);
    return 0;
}

