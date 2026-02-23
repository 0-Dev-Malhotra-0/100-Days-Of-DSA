/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main()
{
	int n, i, val;
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
			ptr = start;
		}
		
		else
		{
			ptr->next = newnode;
			ptr = newnode;
		}
	}
	
	while (start != NULL)
	{
		printf("%d ", start->data);
		start = start->next;
	}
	
	return 0;
}
