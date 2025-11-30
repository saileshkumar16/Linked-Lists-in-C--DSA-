#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main()
{
    struct node *first, *second, *third;
    struct node *head, *tmp;

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
    // INSERT AT END (YOUR STYLE)
    // =============================

    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = 40;

    tmp = head;

    // Move tmp to last node
    do
    {
        tmp = tmp->next;
    }
    while (tmp->next != head);

    nn->next = head;   // new node points to head
    tmp->next = nn;    // last node points to new node

    // =============================
    // PRINT UPDATED CLL
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
