/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

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

struct node* mergeLists(struct node* l1, struct node* l2) {
    struct node dummy;
    struct node* end = &dummy;
    dummy.next = NULL;

    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data) {
            end->next = l1;
            l1 = l1->next;
        } else {
            end->next = l2;
            l2 = l2->next;
        }
        end = end->next;
    }

    if(l1 != NULL)
        end->next = l1;
    else
        end->next = l2;

    return dummy.next;
}

void printList(struct node* start) {
    while(start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct node* list1 = createList(n);

    scanf("%d", &m);
    struct node* list2 = createList(m);

    struct node* merged = mergeLists(list1, list2);

    printList(merged);

    return 0;
}
