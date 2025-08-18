#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;

    // Insert first node
    struct node *newnode = malloc(sizeof(struct node));

    newnode->data = 10;
    newnode->next = NULL;

    if (head == NULL)   // first node case
    {
        head = newnode;
        
    }

    // Insert second node
    newnode = malloc(sizeof(struct node));

    newnode->data = 20;
    newnode->next = NULL;

    if (head == NULL)   // not true anymore
    {
        head = newnode;
    }

    // Link and attach
    struct node *lastnode = head;
    while (lastnode->next != NULL)
    {
        lastnode = lastnode->next;
    }
    lastnode->next = newnode;

    // Insert third node
    newnode = malloc(sizeof(struct node));

    newnode->data = 30;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }

    lastnode = head;
    while (lastnode->next != NULL)
    {
        lastnode = lastnode->next;
    }
    lastnode->next = newnode;

  
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
