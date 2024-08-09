#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char array[MAX];
    int top;
} Stack;

void createStack(Stack *ps) {
    ps->top = 0;
}

int isStackEmpty(Stack *ps) {
    return ps->top == 0;
}

int isStackFull(Stack *ps) {
    return ps->top == MAX;
}

void push(Stack *ps, char item) {
    if (!isStackFull(ps)) {
        ps->array[ps->top++] = item;
    } else {
        printf("Stack is full\n");
    }
}

char pop(Stack *ps) {
    if (!isStackEmpty(ps)) {
        return ps->array[--ps->top];
    } else {
        printf("Stack is empty\n");
        return '\0';
    }
}

char topReading(Stack *ps) {
    if (!isStackEmpty(ps)) {
        return ps->array[ps->top - 1];
    } else {
        return '\0';
    }
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    if (operator == '^') return 3;
    return 0;
}

int isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^';
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    createStack(&s);
    int i, k = 0;
    char symbol, temp;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        if ((symbol >= '0' && symbol <= '9') || (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
            postfix[k++] = symbol;
        } else if (symbol == '(') {
            push(&s, symbol);
        } else if (symbol == ')') {
            while ((temp = pop(&s)) != '(') {
                postfix[k++] = temp;
            }
        } else if (isOperator(symbol)) {
            while (!isStackEmpty(&s) && precedence(topReading(&s)) >= precedence(symbol)) {
                postfix[k++] = pop(&s);
            }
            push(&s, symbol);
        }
    }

    while (!isStackEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
