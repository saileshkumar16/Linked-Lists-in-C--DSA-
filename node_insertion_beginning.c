#include <stdio.h>
#include <stdlib.h>
    struct node
    {
        int data;
        struct node *next;
    };

int main() 
{
    struct node *head = NULL; //empty list 
    
    struct node *newnode1 = malloc(sizeof(struct node)); //create new node
    
    newnode1->data = 10; //give value
    newnode1->next = head; // point the next address
    
    head = newnode1; // update the head
    
    struct node *newnode2 = malloc(sizeof(struct node));
    
    newnode2->data = 20;
    newnode2->next = head;
    
    head = newnode2;
    
    struct node *newnode3 = malloc(sizeof(struct node));
    
    newnode3->data = 30;
    newnode3->next = head;
    
    head = newnode3;
    
    struct node *temp = head;
    
    
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }


    return 0;
}
