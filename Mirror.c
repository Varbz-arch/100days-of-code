// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
// Input:
// - Single line: a lowercase string containing only alphabetic characters  AND NUMBER TOO(no spaces)
// Output:
// - Print the transformed code name after applying the mirror operation
// Example:
// Input:
// hello
// Output:
// olleh
// Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored

#include <stdio.h>

int main() {
    char str[1000];
    int i = 0;
    scanf("%s", str);
    // Find the length manually
    while (str[i] != '\0') {
        i++;
    }
    // Print in reverse
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", str[j]); //but the memory stores the old string
    }
    return 0;
}

// this changes the memory of the string to the new reversed string
// for (int i = n-1, j = 0; i >= 0; i--) {
//     temp[j++] = str[i];
// }