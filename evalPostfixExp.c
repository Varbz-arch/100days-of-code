// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
// Input:
// - Postfix expression with operands and operators
// Output:
// - Print the integer result
// Example:
// Input:
// 2 3 1 * + 9 -
// Output:
// -4
// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push operation
void push(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main() {
    char expr[200];
    fgets(expr, sizeof(expr), stdin);

    char *token = strtok(expr, " \n");

    while (token != NULL) {
        // Operand
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        // Operator
        else {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                case '%':
                    result = a % b;
                    break;
                default:
                    printf("Invalid Operator\n");
                    return 1;
            }

            push(result);
        }

        token = strtok(NULL, " \n");
    }

    printf("%d\n", pop());

    return 0;
}