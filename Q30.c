/* Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

void createPoly(struct node **start, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        scanf("%d",&newnode->coeff);
        
        scanf("%d",&newnode->exp);

        newnode->next = NULL;

        if(*start == NULL)
        {
            *start = newnode;
        }
        
        else
        {
            struct node *ptr = *start;
            while(ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = newnode;
        }
        
    }
}

void displayPoly(struct node *start)
{
    while(start != NULL)
    {
        printf("%dx^%d", start->coeff, start->exp);

        if(start->next != NULL)
            printf(" + ");

        start = start->next;
    }
    printf("\n");
}

int main()
{
    struct node *start = NULL;
    int n;
	
	scanf("%d",&n);
	
    createPoly(&start, n);
    
    displayPoly(start);
    
    return 0;
}
