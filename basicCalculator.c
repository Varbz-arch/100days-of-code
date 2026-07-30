// Given a string s which represents an expression, evaluate this expression and return its value. 
// The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
// Example 1:
// Input: s = "3+2*2"
// Output: 7

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int calculate(char* s) {
    int stack[10000];
    int top = -1;

    int num = 0;
    char op = '+';

    for (int i = 0; ; i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        // Process when operator or end of string
        if ((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0') {

            if (op == '+') {
                stack[++top] = num;
            }
            else if (op == '-') {
                stack[++top] = -num;
            }
            else if (op == '*') {
                stack[top] = stack[top] * num;
            }
            else if (op == '/') {
                stack[top] = stack[top] / num;
            }

            op = s[i];
            num = 0;
        }

        if (s[i] == '\0')
            break;
    }

    int sum = 0;
    while (top != -1) {
        sum += stack[top--];
    }

    return sum;
}

int main() {
    char s[] = "3+2*2";
    printf("%d\n", calculate(s));
    return 0;
}