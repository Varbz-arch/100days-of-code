// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[0] - y[0];
}

int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    int **intervals = malloc(n * sizeof(int *));

    printf("Enter intervals:\n");

    for (int i = 0; i < n; i++)
    {
        intervals[i] = malloc(2 * sizeof(int));

        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    // Sort intervals by start time
    qsort(intervals, n, sizeof(int *), compare);

    int **result = malloc(n * sizeof(int *));
    int count = 0;

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < n; i++)
    {
        // Overlapping
        if (intervals[i][0] <= end)
        {
            if (intervals[i][1] > end)
            {
                end = intervals[i][1];
            }
        }
        // Not overlapping
        else
        {
            result[count] = malloc(2 * sizeof(int));

            result[count][0] = start;
            result[count][1] = end;

            count++;

            // Start new interval
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // Add the last interval
    result[count] = malloc(2 * sizeof(int));
    result[count][0] = start;
    result[count][1] = end;
    count++;

    printf("\nMerged intervals:\n");

    for (int i = 0; i < count; i++)
    {
        printf("[%d, %d]", result[i][0], result[i][1]);

        if (i != count - 1)
            printf(", ");
    }

    printf("\n");

    // Free memory
    for (int i = 0; i < n; i++)
        free(intervals[i]);

    for (int i = 0; i < count; i++)
        free(result[i]);

    free(intervals);
    free(result);

    return 0;
}