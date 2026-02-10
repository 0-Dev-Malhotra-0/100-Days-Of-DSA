/* Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards */

#include <stdio.h>

int main() 
{
    char s[1000];
    scanf("%s", &s);
    
    int len = 0;
    while (s[len] != '\0') 
        len++;
    
    int left = 0, right = len - 1, pal = 1;
    
    while (left < right) 
	{
        if (s[left] != s[right]) 
		{
            pal = 0;
            break;
        }
        
        left++;
        right--;
    }
    
    if (pal == 1) 
        printf("YES");
    else 
        printf("NO");
    
    return 0;
}

