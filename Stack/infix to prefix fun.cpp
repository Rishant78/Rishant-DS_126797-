#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get precedence of operators
int precedence(char ch) {
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(char *infix, char *prefix) {
    char stack[MAX_SIZE]; // Stack to hold operators temporarily
    int top = -1; // Top of the stack

    reverseString(infix);

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
        } else if (isOperator(ch)) {
            while (top != -1 && stack[top] != ')' && precedence(stack[top]) >= precedence(ch)) {
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

    reverseString(prefix);
}

int main() {
    char infix[] = "A-(B/C+(D%E*F)/G)*H"; // Original infix expression
    char prefix[MAX_SIZE]; // To store the prefix expression

    infixToPrefix(infix, prefix);

    printf("Infix expression: %s\n", infix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

