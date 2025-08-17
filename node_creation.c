#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    struct Node* first = (struct Node *)malloc(sizeof(struct Node));
    struct Node* second = (struct Node *)malloc(sizeof(struct Node));
    struct Node* third = (struct Node *)malloc(sizeof(struct Node));
    
    first -> data = 10;
    first -> next = second;
    
    second->data = 20;
    second->next = third;
    
    third->data = 30;
    third->next = NULL;
    
    printf("%d %d %d %p %p %p",first->data, second->data, third->data, first->next, second->next, third->next);

    

    return 0;
}

-----------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
    struct node
    {
        int data;
        struct node *next;
    };

int main() 
{
    struct node *head,*middle,*last;
    
    head = malloc(sizeof(struct node));
    middle = malloc(sizeof(struct node));
    last = malloc(sizeof(struct node));
    
    head-> data = 10;
    middle ->data = 20;
    last -> data = 30;
    
    head->next = middle;
    middle ->next = last;
    last ->next = NULL;
    
    struct node *temp = head;
    
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }


    return 0;
}

