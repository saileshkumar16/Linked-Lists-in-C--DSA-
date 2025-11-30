#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Insert ONE node at beginning
struct node* insert_at_beginning(struct node *head, int value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;   // link new node to old head
    return newNode;         // new head
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

    // Insert new node at beginning
    head = insert_at_beginning(head, 5);

    // Print linked list + count
    int count = 0;
    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }

    printf("NULL\n");
    printf("Node count = %d\n", count);

    return 0;
}
