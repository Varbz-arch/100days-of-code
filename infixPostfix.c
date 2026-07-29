// Problem: Convert an infix expression to postfix notation using stack.
// Input:
// - Single line: infix expression (operands are single characters)
// Output:
// - Print the postfix expression
// Example:
// Input:
// A+B*C
// Output:
// ABC*+
// Explanation:
// Operator precedence: * > +
// Use stack to handle operator precedence and associativity

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char ch) {
    stack[++top] = ch;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Check precedence
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {

        char ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // Left parenthesis
        else if (ch == '(') {
            push(ch);
        }

        // Right parenthesis
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }

        // Operator
        else {
            while (top != -1 &&precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s\n", postfix);

    return 0;
}