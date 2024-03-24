#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char infix[] = "A-(B/C+(D%E*F)/G)*H"; // Original infix expression
    char postfix[MAX_SIZE]; // To store the postfix expression
    char stack[MAX_SIZE]; // Stack to hold operators temporarily
    int top = -1; // Top of the stack

    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if ((ch >= 'A' && ch <= 'H') || ch == '%') {
            postfix[j++] = ch;
        } else if (ch == '(') {
            stack[++top] = '(';
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top != -1) {
                top--; // Pop '('
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top != -1 && stack[top] != '(' && ((ch == '*' || ch == '/') ? (stack[top] == '*' || stack[top] == '/') : 1)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

