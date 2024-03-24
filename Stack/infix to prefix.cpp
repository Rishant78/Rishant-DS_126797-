#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char infix[] = "A-(B/C+(D%E*F)/G)*H"; // Original infix expression
    char prefix[MAX_SIZE]; // To store the prefix expression
    char stack[MAX_SIZE]; // Stack to hold operators temporarily
    int top = -1; // Top of the stack

    // Reverse the infix expression
    strrev(infix);

    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if ((ch >= 'A' && ch <= 'H') || ch == '%') {
            prefix[j++] = ch;
        } else if (ch == ')') {
            stack[++top] = ')';
        } else if (ch == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = stack[top--];
            }
            if (top != -1) {
                top--; // Pop ')'
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top != -1 && stack[top] != ')' && ((ch == '*' || ch == '/') ? (stack[top] == '*' || stack[top] == '/') : 1)) {
                prefix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        prefix[j++] = stack[top--];
    }
    prefix[j] = '\0'; // Null-terminate the prefix expression

    // Reverse the prefix expression to get the final result
    strrev(prefix);

    printf("Infix expression: %s\n", infix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

