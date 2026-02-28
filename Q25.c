/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main()
{
	int key, i, n, val, count = 0;
	struct node *start = NULL, *newnode = NULL,  *ptr = NULL;
	
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
	
	scanf("%d",&key);
	
	ptr = start;
	
    while (ptr != NULL)
    {
        if (ptr->data == key)
            count += 1;
        
        ptr = ptr->next;
    }
	
	printf("%d",count);
	
	return 0;
}
