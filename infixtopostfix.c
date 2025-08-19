#include <stdio.h>
#include <ctype.h>
#define Max 100

char stack[Max];
int top = -1;

void push(char c) {
    if (top < Max - 1) {
        stack[++top] = c;
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

int isOperand(char c) {
    return isalnum(c); // Accepts digits and letters
}

void infixtoPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;
    top = -1; // Reset stack for each conversion
    while ((ch = infix[i++]) != '\0') {
        if (isOperand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix[j++] = pop();
            }
            if (peek() == '(')
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

int canEvaluate(char postfix[]) {
    // Returns 1 if all operands are digits, else 0
    int i = 0;
    char ch;
    while ((ch = postfix[i++]) != '\0') {
        if (isOperand(ch) && !isdigit(ch)) {
            return 0;
        }
    }
    return 1;
}

int evaluatePostfix(char postfix[]) {
    int evalStack[Max];
    int evalTop = -1;
    int i = 0, op1, op2, result;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            evalStack[++evalTop] = ch - '0';
        } else if (isOperator(ch)) {
            if (evalTop < 1) {
                printf("Error: Insufficient operands\n");
                return 0;
            }
            op2 = evalStack[evalTop--];
            op1 = evalStack[evalTop--];

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': 
                    if (op2 == 0) {
                        printf("Error: Division by zero\n");
                        return 0;
                    }
                    result = op1 / op2; 
                    break;
                case '^': 
                    result = 1;
                    for (int j = 0; j < op2; j++)
                        result *= op1;
                    break;
            }
            evalStack[++evalTop] = result;
        }
    }

    if (evalTop != 0) {
        printf("Error: Invalid postfix expression\n");
        return 0;
    }

    return evalStack[evalTop];
}

int main() {
    char infix[Max], postfix[Max];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtoPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    if (canEvaluate(postfix)) {
        printf("Evaluated result: %d\n", evaluatePostfix(postfix));
    } else {
        printf("Evaluation skipped: Expression contains non-numeric operands.\n");
    }

    return 0;
}
