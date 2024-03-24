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

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX_SIZE]; // Stack to hold operators temporarily
    int top = -1; // Top of the stack
    int j = 0; // Index for postfix expression

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if ((ch >= 'A' && ch <= 'H') || ch == '%') {
            postfix[j++] = ch; // Operand
        } else if (ch == '(') {
            stack[++top] = '(';
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--]; // Pop operators until '('
            }
            if (top != -1) {
                top--; // Pop '('
            }
        } else if (isOperator(ch)) {
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = stack[top--]; // Pop operators with higher precedence
            }
            stack[++top] = ch;
        }
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[] = "A-(B/C+(D%E*F)/G)*H"; // Original infix expression
    char postfix[MAX_SIZE]; // To store the postfix expression

    infixToPostfix(infix, postfix);

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

