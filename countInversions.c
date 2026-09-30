// Problem: Count number of inversions using modified merge sort.
// Inversion if i < j and a[i] > a[j].

#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    long long inversions = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            // All remaining elements in left half
            // are greater than arr[j]
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inversions;
}

long long mergeSort(int arr[], int temp[], int left, int right)
{
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    long long inversions = 0;

    inversions += mergeSort(arr, temp, left, mid);
    inversions += mergeSort(arr, temp, mid + 1, right);

    inversions += merge(arr, temp, left, mid, right);

    return inversions;
}

long long countInversions(int arr[], int n)
{
    int *temp = (int *)malloc(n * sizeof(int));

    long long result = mergeSort(arr, temp, 0, n - 1);

    free(temp);

    return result;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long ans = countInversions(arr, n);

    printf("Number of inversions = %lld\n", ans);

    return 0;
}