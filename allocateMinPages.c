// Problem Statement
// Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

// Books must be allocated in contiguous order.

// Input Format
// n m
// n space-separated integers representing pages in books

// Output Format
// Print the minimum possible value of the maximum pages assigned to any student.

// Sample Input
// 4 2
// 12 34 67 90

// Sample Output
// 113

// Explanation
// One optimal allocation is:
// Student 1: 12 + 34 + 67 = 113
// Student 2: 90
// Maximum pages = 113 (minimum possible).

#include <stdio.h>

int canAllocate(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {

        // If adding this book does not exceed maxPages
        if (currentPages + pages[i] <= maxPages) {
            currentPages += pages[i];
        }
        else {
            // Give books to a new student
            students++;
            currentPages = pages[i];

            // More students than available
            if (students > m) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int pages[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Minimum possible answer = largest single book
    int low = pages[0];

    // Maximum possible answer = sum of all pages
    int high = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > low) {
            low = pages[i];
        }

        high += pages[i];
    }

    int answer = high;

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(pages, n, m, mid)) {
            // This maximum is possible.
            // Try to find an even smaller maximum.
            answer = mid;
            high = mid - 1;
        }
        else {
            // This maximum is too small.
            low = mid + 1;
        }
    }

    printf("%d\n", answer);

    return 0;
}