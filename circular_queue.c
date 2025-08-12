#include <stdio.h>
#define Max 100

char stack[Max];
int top = -1;

void push(char c) {
    if (top < Max - 1) {
        top++;
        stack[top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

void infixtoPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isDigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        } else if (isOperator(ch)) {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int evalStack[Max];
    int evalTop = -1;
    int i = 0, op1, op2, result;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isDigit(ch)) {
            evalStack[++evalTop] = ch - '0';
        } else if (isOperator(ch)) {
            op2 = evalStack[evalTop--];
            op1 = evalStack[evalTop--];

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': {
                    result = 1;
                    for (int j = 0; j < op2; j++)
                        result *= op1;
                    break;
                }
            }
            evalStack[++evalTop] = result;
        }
    }

    return evalStack[evalTop];
}

int main() {
    char infix[Max], postfix[Max];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtoPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Evaluated result: %d\n", evaluatePostfix(postfix));

    return 0;
}
