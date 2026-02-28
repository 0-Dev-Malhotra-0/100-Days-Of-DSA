/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
    int i, n, val;
    struct node *start = NULL, *newnode = NULL, *ptr = NULL;
    
    scanf("%d",&n);
    
    for (i = 0; i < n; i++)
    {
        scanf("%d",&val);
        
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;
        
        if (start == NULL)
        {
            start = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->next = newnode;
            ptr = newnode;
        }
    }
    
    if (ptr != NULL)
        ptr->next = start;
    
    if (start != NULL)
    {
        ptr = start;
        do
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        while (ptr != start);
        
        printf("(back to start)");
    }
    
    return 0;
}
