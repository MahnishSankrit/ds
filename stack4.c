#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char* str) {
    if (top < MAX - 1) {
        strcpy(stack[++top], str);
    }
}

char* pop() {
    if (top != -1) {
        return stack[top--];
    }
    return NULL;
}

char* peek() {
    if (top != -1) {
        return stack[top];
    }
    return NULL;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void reverse(char* exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z')) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && *peek() != '(') {
                postfix[j++] = *pop();
            }
            pop();
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(*peek()) >= precedence(infix[i])) {
                postfix[j++] = *pop();
            }
            push(&infix[i]);
        }
    }
    while (top != -1) {
        postfix[j++] = *pop();
    }
    postfix[j] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    int n = strlen(infix);

    reverse(infix);

    for (int i = 0; i < n; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix);

    reverse(postfix);
    strcpy(prefix, postfix);
}

void postfixToInfix(char* postfix, char* infix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        if ((postfix[i] >= 'A' && postfix[i] <= 'Z') || (postfix[i] >= 'a' && postfix[i] <= 'z')) {
            char op[2] = {postfix[i], '\0'};
            push(op);
        } else if (isOperator(postfix[i])) {
            char op2[MAX];
            strcpy(op2, pop());
            char op1[MAX];
            strcpy(op1, pop());

            char temp[MAX] = "(";

            strcat(temp, op1);
            char operator[2] = {postfix[i], '\0'};
            strcat(temp, operator);
            strcat(temp, op2);
            strcat(temp, ")");

            push(temp);
        }
    }

    strcpy(infix, pop());
}

void prefixToInfix(char* prefix, char* infix) {
    int n = strlen(prefix);

    for (int i = n - 1; i >= 0; i--) {
        if ((prefix[i] >= 'A' && prefix[i] <= 'Z') || (prefix[i] >= 'a' && prefix[i] <= 'z')) {
            char op[2] = {prefix[i], '\0'};
            push(op);
        } else if (isOperator(prefix[i])) {
            char op1[MAX];
            strcpy(op1, pop());
            char op2[MAX];
            strcpy(op2, pop());

            char temp[MAX] = "(";
            strcat(temp, op1);
            char operator[2] = {prefix[i], '\0'};
            strcat(temp, operator);
            strcat(temp, op2);
            strcat(temp, ")");

            push(temp);
        }
    }

    strcpy(infix, pop());
}

void postfixToPrefix(char* postfix, char* prefix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        if ((postfix[i] >= 'A' && postfix[i] <= 'Z') || (postfix[i] >= 'a' && postfix[i] <= 'z')) {
            char op[2] = {postfix[i], '\0'};
            push(op);
        } else if (isOperator(postfix[i])) {
            char op2[MAX];
            strcpy(op2, pop());
            char op1[MAX];
            strcpy(op1, pop());

            char temp[MAX];
            temp[0] = postfix[i];
            temp[1] = '\0';
            strcat(temp, op1);
            strcat(temp, op2);

            push(temp);
        }
    }

    strcpy(prefix, pop());
}

void prefixToPostfix(char* prefix, char* postfix) {
    int n = strlen(prefix);

    for (int i = n - 1; i >= 0; i--) {
        if ((prefix[i] >= 'A' && prefix[i] <= 'Z') || (prefix[i] >= 'a' && prefix[i] <= 'z')) {
            char op[2] = {prefix[i], '\0'};
            push(op);
        } else if (isOperator(prefix[i])) {
            char op1[MAX];
            strcpy(op1, pop());
            char op2[MAX];
            strcpy(op2, pop());

            char temp[MAX];
            strcpy(temp, op1);
            strcat(temp, op2);
            char operator[2] = {prefix[i], '\0'};
            strcat(temp, operator);

            push(temp);
        }
    }

    strcpy(postfix, pop());
}

int main() {
    char infix[MAX], prefix[MAX], postfix[MAX], result[MAX];
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Postfix to Infix\n");
        printf("4. Prefix to Infix\n");
        printf("5. Postfix to Prefix\n");
        printf("6. Prefix to Postfix\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an infix expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix expression: %s\n", postfix);
                break;

            case 2:
                printf("Enter an infix expression: ");
                scanf("%s", infix);
                infixToPrefix(infix, prefix);
                printf("Prefix expression: %s\n", prefix);
                break;

            case 3:
                printf("Enter a postfix expression: ");
                scanf("%s", postfix);
                postfixToInfix(postfix, result);
                printf("Infix expression: %s\n", result);
                break;

            case 4:
                printf("Enter a prefix expression: ");
                scanf("%s", prefix);
                prefixToInfix(prefix, result);
                printf("Infix expression: %s\n", result);
                break;

            case 5:
                printf("Enter a postfix expression: ");
                scanf("%s", postfix);
                postfixToPrefix(postfix, result);
                printf("Prefix expression: %s\n", result);
                break;

            case 6:
                printf("Enter a prefix expression: ");
                scanf("%s", prefix);
                prefixToPostfix(prefix, result);
                printf("Postfix expression: %s\n", result);
                break;

            case 7:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
