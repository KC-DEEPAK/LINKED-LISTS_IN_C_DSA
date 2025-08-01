#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
    };
void getlength(struct node **head)
{
    int count=1;
    struct node *temp;
    temp=*head;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("length is %d .\n",count);

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

getlength(&head);
    printf("linked list after delete :");
    temp=head;
    while(temp!=NULL){
        printf("%d-> ", temp->data);
        temp=temp->next;
    }
    printf("Null\n");

    return 0;
}