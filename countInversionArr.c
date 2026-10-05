// Problem: For each element, count how many smaller elements appear on right side.
// Use merge sort technique or Fenwick Tree (BIT).

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[][2], int temp[][2], int count[], 
           int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = left;
    int rightSmaller = 0;

    while (i <= mid && j <= right) {

        if (arr[j][0] < arr[i][0]) {
            // arr[j] is smaller than arr[i]
            rightSmaller++;
            temp[k][0] = arr[j][0];
            temp[k][1] = arr[j][1];
            j++;
            k++;
        }
        else {
            // All previously taken right elements
            // are smaller than arr[i]
            count[arr[i][1]] += rightSmaller;

            temp[k][0] = arr[i][0];
            temp[k][1] = arr[i][1];

            i++;
            k++;
        }
    }

    // Remaining left elements
    while (i <= mid) {
        count[arr[i][1]] += rightSmaller;

        temp[k][0] = arr[i][0];
        temp[k][1] = arr[i][1];

        i++;
        k++;
    }

    // Remaining right elements
    while (j <= right) {
        temp[k][0] = arr[j][0];
        temp[k][1] = arr[j][1];

        j++;
        k++;
    }

    // Copy back
    for (i = left; i <= right; i++) {
        arr[i][0] = temp[i][0];
        arr[i][1] = temp[i][1];
    }
}

void mergeSort(int arr[][2], int temp[][2], int count[],
               int left, int right) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, temp, count, left, mid);
    mergeSort(arr, temp, count, mid + 1, right);

    merge(arr, temp, count, left, mid, right);
}

int main() {

    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int arr[n][2];
    int temp[n][2];
    int count[n];

    // Store {value, original index}
    for (int i = 0; i < n; i++) {
        arr[i][0] = nums[i];
        arr[i][1] = i;
        count[i] = 0;
    }

    mergeSort(arr, temp, count, 0, n - 1);

    printf("Answer: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}