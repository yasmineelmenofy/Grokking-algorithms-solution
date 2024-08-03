#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTACK 100

typedef struct stack {
    char array[MAXSTACK];
    int top;
} stack;

void createStack(stack *ps) {
    ps->top = 0;
}

int stackEmpty(stack *ps) {
    return ps->top == 0;
}

void push(char e, stack *ps) {
    if (ps->top < MAXSTACK) {
        ps->array[ps->top++] = e;
    } else {
        printf("Stack is full\n");
    }
}

char pop(stack *ps) {
    if (!stackEmpty(ps)) {
        return ps->array[--ps->top];
    } else {
        printf("Stack is empty\n");
        return '\0';
    }
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int isValidParentheses(const char *expression) {
    stack s;
    createStack(&s);
    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c, &s);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stackEmpty(&s) || !isMatchingPair(pop(&s), c)) {
                return 0;
            }
        }
    }
    return stackEmpty(&s);
}

int main() {
    const char *expression = "[{()}]";
    if (isValidParentheses(expression)) {
        printf("The expression \"%s\" is valid.\n", expression);
    } else {
        printf("The expression \"%s\" is invalid.\n", expression);
    }
    return 0;
}
