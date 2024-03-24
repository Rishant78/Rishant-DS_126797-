#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a character is an operator
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

// Function to reverse a string using pointers
void reverseString(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to convert infix to prefix using pointers
void infixToPrefix(char *infix, char *prefix) {
    char stack[MAX_SIZE]; // Stack to hold operators temporarily
    int top = -1; // Top of the stack
    int j = 0; // Index for prefix expression

    // Reverse the infix expression
    reverseString(infix);

    for (char *ptr = infix; *ptr != '\0'; ptr++) {
        char ch = *ptr;
        if ((ch >= 'A' && ch <= 'H') || ch == '%') {
            prefix[j++] = ch; // Operand
        } else if (ch == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = stack[top--]; // Pop operators until '('
            }
            if (top != -1) {
                top--; // Pop '('
            }
        } else if (isOperator(ch)) {
            while (top != -1 && stack[top] != ')' && precedence(stack[top]) >= precedence(ch)) {
                prefix[j++] = stack[top--]; // Pop operators with higher precedence
            }
            stack[++top] = ch;
        } else if (ch == ')') {
            stack[++top] = ch;
        }
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        prefix[j++] = stack[top--];
    }

    prefix[j] = '\0'; // Null-terminate the prefix expression

    // Reverse the prefix expression to get the final result
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

