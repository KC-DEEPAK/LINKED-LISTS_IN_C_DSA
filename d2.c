#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;//just we are declare the reqired parts of one node are data and *next means the store the address of next
};

void main() {
    struct node *head = NULL, *newnode, *temp;//we want *head pointer and also nead a newnode pointer,temp to store or travarsing the linked list.
    int choice = 1;//while choice 1 represnting a should continue

    while (choice) {
        newnode = (struct node*) malloc(sizeof(struct node));//we are allocating a memory at run time 
        if (newnode == NULL) {//when the newnode ==null the memory allocaion is faild
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter the data: ");//1st we are asking a user to enter the data 
        scanf("%d", &newnode->data);//storing a data from user .
        newnode->next = NULL;//also new conting a address part which is null

        if (head == NULL) {//when head is equal to null
            head = temp = newnode;//head =temp=newnode
        } else {
            temp->next = newnode;//temp which is used as a variable temp->next=newnode means that temp node next is equal to newnode
            temp = newnode;//temp is equal to newmode
        }

        printf("Do you want to continue (1 for Yes / 0 for No)? ");// asking a user that user may enter the more data .
        scanf("%d", &choice);
    }

    // Printing the linked list
    printf("Linked list: ");
    temp = head;
    while (temp != NULL) {//while printing a data temp when not equal null
        printf("%d -> ", temp->data);// it points to the data of temp
        temp = temp->next;//it points to the addresss next part. 
    }
    printf("NULL\n");
}
