/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main()
{
	int key, i, n, val;
	struct node *start = NULL, *newnode = NULL,  *ptr = NULL, *preptr = NULL;
	
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
    preptr = NULL;
    
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            if (preptr == NULL)   
            {
                start = ptr->next;
            }
            else
            {
                preptr->next = ptr->next;
            }
            
            free(ptr);
            break;   
        }
        
        preptr = ptr;
        ptr = ptr->next;
    }
	
	ptr = start;
	
	while (ptr != NULL)
	{
		printf("%d -> ",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
	
	return 0;
}
