/* Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10 */

#include <stdio.h>  

int stack[100];
int top = -1;    

void push(int value) 
{
    if (top == 99) 
	{
        printf("Stack Overflow\n");
        return;
    }
    
    stack[++top] = value;
}

void pop() 
{
    if (top == -1) 
	{
        printf("Stack Underflow\n");
        return;
    }
    
    printf("%d\n", stack[top--]);
}

void display() 
{
	int i;
		
    if (top == -1) 
	{	
        printf("Stack is Empty\n");
        return;
	}
	
    for (i = top; i >= 0; i--) 
        printf("%d ", stack[i]);

    printf("\n");
}

int main() 
{
    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
	{
        int operation, value;
        scanf("%d", &operation);

        if (operation == 1) 
        {
        	scanf("%d", &value);
            push(value);
		}

        else if (operation == 2) 
            pop();
            
        else if (operation == 3) 
            display();
            
        else 
        	printf("Invalid Option.");
    }

    return 0;
}
