#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
    };
int delete_begining(struct node **head){
    if(*head==NULL){
        printf("list is empty");
    }
    else{
        struct node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}
void delete_end(struct node **head){
    struct node *temp=*head;
    struct node *prevnode=NULL;
    while(temp->next!=NULL){
        prevnode=temp;
        temp=temp->next;
    }
    if(*head==temp){
        *head=0;
    }
    else{
        prevnode->next=NULL;
    }
    free(temp);
}
void delete_pos(struct node **head){
    struct node *nextnode,*temp;
    int pos,i=1;
    printf( "enter the location you want to delete :");
    scanf("%d",&pos);
    temp=*head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}
int main(){
    struct node *head=0,*newnode,*temp;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==0){
            printf("memory allocation not be done.\n");
           // return;
        }
        printf("enter the data :");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("do you want to continue (1 for yes / 0 for no)?: ");
        scanf("%d",&choice);
    }
    printf("linked list before delete :");
    temp=head;
    while(temp!=NULL){
        printf("%d-> ", temp->data);
        temp=temp->next;
    }
    printf("Null\n");

    delete_begining(&head);
    delete_end(&head);
    delete_pos(&head);
    printf("linked list after delete :");
    temp=head;
    while(temp!=NULL){
        printf("%d-> ", temp->data);
        temp=temp->next;
    }
    printf("Null\n");

    return 0;
}
//CODE IS OK CHEKED
