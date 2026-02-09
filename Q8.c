/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/

#include<stdio.h>

int power(int a, int b)
{
	int prod = 1, i;
	
	if (b==0)
		return 1;
	
	else
	{
		for (i = 1; i <= b; i++)
			prod *= a;
		
		return prod; 
	}
}

int main()
{
	int a, b;
	
	scanf("%d %d",&a,&b);
	printf("%d",power(a,b));
	
	return 0;
}
