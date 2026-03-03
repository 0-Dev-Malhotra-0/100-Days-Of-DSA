/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
    struct node *start = NULL, *ptr = NULL, *newnode, *last, *newLast;
    
    int n, i, k, length = 1;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));  // fixed ;
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (start == NULL)
        {
            start = newnode;
            ptr = start;
        }
        
        else
        {
            ptr->next = newnode;
            ptr = newnode;
        }
    } 
    
    scanf("%d", &k);

    if (start == NULL || k == 0)
        return 0;

    last = start;
    while (last->next != NULL)
    {
        last = last->next;
        length++;
    }
    
    last->next = start;

    k = k % length;

    int steps = length - k;
    newLast = start;

    for (i = 1; i < steps; i++)
        newLast = newLast->next;
    

    start = newLast->next;
    newLast->next = NULL;

    ptr = start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
    return 0;
}
