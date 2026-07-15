// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int minSum = arr[0] + arr[1];

    int x = arr[0];
    int y = arr[1];

    // Check every pair
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            // Is this sum closer to zero?
            if(abs(sum) < abs(minSum))
            {
                minSum = sum;
                x = arr[i];
                y = arr[j];
            }
        }
    }

    printf("Pair: %d %d\n", x, y);
    printf("Sum: %d\n", minSum);

    return 0;
}