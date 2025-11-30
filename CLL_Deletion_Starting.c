#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main()
{
    struct node *first, *second, *third;
    struct node *head, *tmp, *d;

    // Create 3 nodes
    first  = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third  = (struct node*)malloc(sizeof(struct node));

    first->data  = 10;
    second->data = 20;
    third->data  = 30;

    // Make it circular
    first->next  = second;
    second->next = third;
    third->next  = first;

    head = first;

    // =============================
    // DELETE AT BEGINNING (YOUR LOGIC)
    // =============================

    tmp = head;      // tmp starts at head
    d = head;        // node to delete

    // Move tmp to LAST node
    do
    {
        tmp = tmp->next;
    }
    while (tmp->next != head);

    // Re-link last node to second node
    tmp->next = head->next;

    // Update head
    head = head->next;

    // Free old head
    free(d);

    // =============================
    // PRINT UPDATED CIRCULAR LIST
    // =============================

    tmp = head;

    do
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    while (tmp != head);

    printf("(back to head)\n");

    return 0;
}
