#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Insert at specific position (1-based index)
struct node* insert_at_position(struct node *head, int value, int pos)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    // Case 1: Insert at position 1
    if (pos == 1)
    {
        newNode->next = head;    // link new node to old head
        return newNode;          // new node becomes head
    }

    struct node *temp = head;
    int i = 1;

    // Move temp to the (pos - 1)th node
    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    // If position is invalid (beyond list length)
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }

    // Insert new node safely
    newNode->next = temp->next;   // Step 1: Point new node to next node
    temp->next = newNode;         // Step 2: Link (pos - 1)th node to new node

    return head;
}

// Print and count nodes
void print_list(struct node *head)
{
    struct node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }

    printf("NULL\n");
    printf("Total nodes: %d\n", count);
}

int main()
{
    struct node *first, *second, *third;
    struct node *head;

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
    third->next  = NULL;

    // Mark head
    head = first;

    printf("Original List:\n");
    print_list(head);

    // Insert at specific position
    head = insert_at_position(head, 25, 2);  // insert 25 at position 2

    printf("\nAfter insertion at position 2:\n");
    print_list(head);

    return 0;
}
