#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    struct Node* head = malloc(sizeof(struct Node)); // first node
    struct Node* temp;

    head->data = 45;
    head->next = malloc(sizeof(struct Node)); //second node
    
    
    head->next->data = 98;
    head->next->next= malloc(sizeof(struct Node)); //third node
    
    head->next->next->data = 3;
    head->next->next->next = NULL; //third node
    
    temp = head;
    int count = 0;
    
    while(temp!=NULL)
    {
        printf("%d %p ",temp->data,temp->next);
        temp = temp->next;
        count++;
    }
    printf("\n");
    
    printf("Total no of nodes are %d",count);


    return 0;
}
