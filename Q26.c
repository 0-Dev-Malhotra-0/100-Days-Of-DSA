/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

int main()
{
	int i, n, val;
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
			newnode->prev = NULL;
			start = newnode;
			ptr = newnode;
		}
		
		else
		{
			newnode->prev = ptr;
			ptr->next = newnode;
			ptr = newnode;
		}
	}
	
	ptr = start;
	
	while (ptr != NULL)
	{
		printf("%d <-> ",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
	
	return 0;
}
