// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Evaluate the expression. Return an integer that represents the value of the expression.
// Note that:
// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.
// Example 1:
// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:
// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Function to evaluate Reverse Polish Notation
int evalRPN(char *tokens[], int tokensSize) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {

        // Check if token is an operator
        if (strcmp(tokens[i], "+") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a + b;
        }
        else if (strcmp(tokens[i], "-") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a - b;
        }
        else if (strcmp(tokens[i], "*") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a * b;
        }
        else if (strcmp(tokens[i], "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a / b;   // Division truncates toward zero
        }
        else {
            // Token is a number
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}

int main() {
    // Example 1
    char *tokens1[] = {"2", "1", "+", "3", "*"};
    int size1 = sizeof(tokens1) / sizeof(tokens1[0]);

    printf("Result 1 = %d\n", evalRPN(tokens1, size1));

    // Example 2
    char *tokens2[] = {"4", "13", "5", "/", "+"};
    int size2 = sizeof(tokens2) / sizeof(tokens2[0]);

    printf("Result 2 = %d\n", evalRPN(tokens2, size2));

    return 0;
}