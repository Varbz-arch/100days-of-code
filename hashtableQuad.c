// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps..


#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, n;

    scanf("%d", &m);
    scanf("%d", &n);

    int hashTable[m];

    // Initialize hash table
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    char operation[10];
    int key;

    for (int op = 0; op < n; op++) {
        scanf("%s %d", operation, &key);

        int h = key % m;

        if (strcmp(operation, "INSERT") == 0) {

            // Quadratic probing:
            // h(k,i) = (h(k) + i*i) % m
            for (int i = 0; i < m; i++) {
                int index = (h + i * i) % m;

                if (hashTable[index] == EMPTY) {
                    hashTable[index] = key;
                    break;
                }
            }

        } else if (strcmp(operation, "SEARCH") == 0) {

            int found = 0;

            for (int i = 0; i < m; i++) {
                int index = (h + i * i) % m;

                if (hashTable[index] == EMPTY) {
                    break;
                }

                if (hashTable[index] == key) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}