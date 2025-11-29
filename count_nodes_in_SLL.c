#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() 
{
    // Step 1: Create 3 node pointers
    struct node *first, *second, *third;
    struct node *head, *temp;

    // Step 2: Allocate memory for each node
    first  = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third  = (struct node*)malloc(sizeof(struct node));

    // Step 3: Assign data
    first->data  = 10;
    second->data = 20;
    third->data  = 30;

    // Step 4: Link the nodes
    first->next  = second;   // 10 → 20
    second->next = third;    // 20 → 30
    third->next  = NULL;     // end of list

    // Step 5: Mark head
    head = first;

    // Step 6: Traverse and print
    int count = 0;
    temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("%d\n", count);   // <-- your fixed line
    printf("NULL\n");

    return 0;
}
