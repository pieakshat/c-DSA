#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct
{
    char items[MAX_SIZE][MAX_SIZE];
    int top;
} Stack;

// initialise the stack
void initialisation(Stack *s)
{
    s->top = -1;
}

// is the stack full?
int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

// is the stack empty?
int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char *item)
{
    if (isFull(s))
    {
        printf("stack is full");
        return;
    }
    strcpy(s->items[++s->top], item);
}

char *pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("stack is empty");
        return NULL;
    }
    return s->items[s->top--];
}

void convert(char *postfix)
{

    Stack s;
    initialisation(&s);
    char token[MAX_SIZE];

    for (int i = 0; i < strlen(postfix); i++)
    {
        // If the character is an operand, push it to the stack
        if (isalnum(postfix[i]))
        {
            char op[2] = {postfix[i], '\0'}; // Convert char to string
            push(&s, op);
        }
        // If the character is an operator, pop two operands and form an infix expression
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            char op2[MAX_SIZE], op1[MAX_SIZE], newExpr[MAX_SIZE];

            strcpy(op2, pop(&s));
            strcpy(op1, pop(&s));

            snprintf(newExpr, sizeof(newExpr), "(%s %c %s)", op1, postfix[i], op2);
            push(&s, newExpr);
        }
    }

    if (!isEmpty(&s))
    {
        printf("Infix Expression: %s\n", pop(&s));
    }
}

int main()
{
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    convert(postfix);

    return 0;
}
