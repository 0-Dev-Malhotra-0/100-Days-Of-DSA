/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* createList(int n){
    int i, val;
    struct node *start = NULL, *newnode = NULL, *ptr = NULL;
    
    for (i = 0; i < n; i++)
    {
        scanf("%d",&val);
        
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
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
    return start;
}

int check_intersection(struct node* l1, struct node* l2)
{
    struct node *ptr1 = l1;
    struct node *ptr2;

    while(ptr1 != NULL)
    {
        ptr2 = l2;
        while(ptr2 != NULL)
        {
            if(ptr1->data == ptr2->data)
                return ptr1->data;

            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return -1;
}

int main()
{
    int n, m, result;
    
    scanf("%d",&n);
    struct node* list1 = createList(n);

    scanf("%d",&m);
    struct node* list2 = createList(m);

    result = check_intersection(list1, list2);
    
    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}
