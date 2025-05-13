#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void evaluate()
{
    char s[100];
    printf("enter the string: ");
    scanf("%s", s);

    int stack[100]; // holds operands
    int top = -1;

    for (int i = 0; i < strlen(s); i++)
    {
        // If the character is an operand, push it onto the stack
        if (isdigit(s[i]))
        {
            stack[++top] = s[i] - '0'; // Convert char to int and push onto the stack
        }
        // If the character is an operator, pop two elements and apply the operator
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            int b = stack[top--]; // Pop the top element
            int a = stack[top--]; // Pop the next element

            int result;
            switch (s[i])
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            }

            stack[++top] = result; // result back to the stack
        }
    }

    printf("Result of postfix evaluation: %d\n", stack[top]);
}

int main()
{
    evaluate();
}