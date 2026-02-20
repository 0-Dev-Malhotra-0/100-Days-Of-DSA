/* Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/

#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int left = 0;
    int right = n - 1;

    int min_sum = arr[left] + arr[right];
    int min_left = left;
    int min_right = right;

    while(left < right)
    {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            min_left = left;
            min_right = right;
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", arr[min_left], arr[min_right]);

    return 0;
}
