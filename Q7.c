/*Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6*/

#include <stdio.h>

int Fibonacci (int n)
{
	
    if (n == 0)
    	return 0;
    if (n == 1)
    	return 1;

    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main()
{
	int N;
    scanf("%d",&N);
    
    if (N<0)
    	printf("Error!!!\nInvalid Input");
    	
	else
    	printf("%d",Fibonacci(N));
    
    return 0;
} 
