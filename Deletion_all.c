#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// ===========================
// Print List
// ===========================
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

// ===========================
// Delete at Beginning
// ===========================
struct node* delete_at_beginning(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    struct node *tmp = head;
    struct node *d = tmp;

    head = head->next;   // Move head
    free(d);             // Delete old head

    return head;
}

// ===========================
// Delete at End (YOUR logic)
// ===========================
struct node* delete_at_end(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    // If list has only one node
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct node *tmp = head;
    struct node *d;

    // Move to second-last node
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    d = tmp->next;      // last node
    tmp->next = NULL;   // break link
    free(d);            // delete last node

    return head;
}

// ===========================
// Delete at Specific Position (0-based indexing)
// ===========================
struct node* delete_at_position(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    // Case 1: pos = 0 → delete at beginning
    if (pos == 0)
    {
        return delete_at_beginning(head);
    }

    // Case 2: pos >= 1
    struct node *tmp = head;

    // Move to (pos - 1)th node
    for (int i = 0; i < pos - 1; i++)
    {
        if (tmp == NULL)
        {
            printf("Invalid position\n");
            return head;
        }
        tmp = tmp->next;
    }

    // Check if next node exists
    if (tmp->next == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    struct node *d = tmp->next;     // node to delete
    tmp->next = d->next;            // bypass
    free(d);                        // delete

    return head;
}

// ===========================
// MAIN
// ===========================
int main()
{
    struct node *first, *second, *third;
    struct node *head;

    // Create 3 nodes
    first  = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third  = (struct node*)malloc(sizeof(struct node));

    first->data  = 10;
    second->data = 20;
    third->data  = 30;

    first->next  = second;
    second->next = third;
    third->next  = NULL;

    head = first;

    printf("Original List:\n");
    print_list(head);

    // Delete at beginning
    head = delete_at_beginning(head);
    printf("\nAfter deleting at beginning:\n");
    print_list(head);

    // Delete at end
    head = delete_at_end(head);
    printf("\nAfter deleting at end:\n");
    print_list(head);

    // Delete at specific position (0-based)
    // Example: delete position 0
    head = delete_at_position(head, 0);
    printf("\nAfter deleting at position 0:\n");
    print_list(head);

    return 0;
}
