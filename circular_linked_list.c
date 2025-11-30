#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

int main()
{
    struct node *first, *second, *third;
    struct node *head, *temp;

    // Create 3 nodes
    first  = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third  = (struct node*)malloc(sizeof(struct node));

    // Assign data
    first->data  = 10;
    second->data = 20;
    third->data  = 30;

    // Link nodes
    first->next  = second;
    second->next = third;
    third->next  = first;   // VERY IMPORTANT: make it circular

    // Mark head
    head = first;

    // Print circular linked list (stop when you reach head again)
    temp = head;
    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);   // stop when we return to head

    printf("(back to head)\n");

    return 0;
}
