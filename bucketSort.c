// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.

#include <stdio.h>

void bucketSort(float arr[], int n) {
    float buckets[n][n];
    int count[n];

    // Initially all buckets are empty
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Step 1: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];

        buckets[index][count[index]] = arr[i];
        count[index]++;
    }

    // Step 2: Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < count[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }

            buckets[i][k + 1] = key;
        }
    }

    // Step 3: Concatenate buckets
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter %d numbers between 0 and 1:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}