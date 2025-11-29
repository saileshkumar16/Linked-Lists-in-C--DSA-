#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

// Insert ONE node at end
struct node* insert_at_end(struct node *head, int value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
        return newNode;

    // Traverse to last node
    struct node *temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }

    // Link last node to new node
    temp->next = newNode;

    return head;  // head remains same
}

int main() 
{
    struct node *first, *second, *third;
    struct node *head, *temp;

    // Allocate 3 nodes
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
    third->next  = NULL;

    // Set head
    head = first;

    // Insert new node at end
    head = insert_at_end(head, 40);

    // Print linked list + count
    int count = 0;
    temp = head;

    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }

    printf("NULL\n");
    printf("Node count = %d\n", count);

    return 0;
}
