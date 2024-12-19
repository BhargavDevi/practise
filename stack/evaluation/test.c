#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include<string.h>
float stack[30];
int sp;

// Push a value onto the stack
void push(int res) {
    if (sp >= 29) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++sp] = res;
}

// Pop a value from the stack
int pop() {
    if (sp < 0) {
        printf("Stack Underflow\n");
        return -1; // Return an invalid value to indicate error
    }
    return stack[sp--];
}

// Evaluate an operation
int eval(char sym) {
    int op1, op2, res;
    if (sp < 1) {
        printf("Invalid expression\n");
        return 0;
    }

    op2 = pop();
    op1 = pop();
    switch (sym) {
        case '+':
            res = op1 + op2;
            break;
        case '-':
            res = op1 - op2;
            break;
        case '*':
            res = op1 * op2;
            break;
        case '^':
            res = pow(op1, op2);
            break;
        case '/':
            if (op2 != 0) {
                res = op1 / op2;
                break;
            } else {
                printf("Division by zero error\n");
                return 0;
            }
        case '%':
            if (op2 != 0) {
                res = op1 % op2;
                break;
            } else {
                printf("Modulo by zero error\n");
                return 0;
            }
        default:
            printf("Invalid operator: %c\n", sym);
            return 0;
    }
    return res;
}

// Evaluate a postfix expression
void evalexp(char exp[]) {
    float value[256], v, res;
    int i = 0;
    char sym;

    // Initialize value array to -1
    for (i = 0; i < 256; i++) {
        value[i] = -1;
    }

    i = 0;
    while ((sym = exp[i++]) != '\0') {
        if (isalnum(sym)) {
            if (isdigit(sym)) {
                push(sym - '0'); // Convert character to integer
            } else {
                if (value[(int)sym] != -1) {
                    push(value[(int)sym]);
                } else {
                    printf("Enter the value for %c: ", sym);
                    scanf("%f", &v);
                    push(value[(int)sym] = v);
                }
            }
        } else {
            res = eval(sym);
            push(res);
        }
    }
}

int main() {
    sp = -1;
    char exp[30];
    int choice;

    printf("Evaluation of expressions\n");
    printf("1. Postfix\n2. Prefix\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            printf("Enter the postfix expression: ");
            scanf("%s", exp);
            evalexp(exp);

            if (sp == 0) {
                printf("Result: %d\n", (int)pop());
            } else {
                printf("Invalid expression!\n");
            }
            break;

        case 2:
            printf("Enter the prefix expression: ");
            scanf("%s", exp);
            strrev(exp);  // Reverse the prefix expression for evaluation
            evalexp(exp);
            strrev(exp);  // Reverse back the prefix expression (optional)

            if (sp == 0) {
                printf("Result: %d\n", (int)pop());
            } else {
                printf("Invalid expression!\n");
            }
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
