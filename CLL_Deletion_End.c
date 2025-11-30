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
    // DELETE AT END (YOUR LOGIC)
    // =============================

    tmp = head;      // start from head

    do
    {
        tmp = tmp->next;     // move tmp forward
    }
    while (tmp->next->next != head);
    // tmp now is the second-last node

    d = tmp->next;   // d is last node
    tmp->next = head; // second-last node points to head

    free(d);         // delete last node

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
