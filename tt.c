#include <stdio.h>;
#include <string.h>;
#include <stdbool.h>;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
}

void convert()
{
    char s[100];
    printf("ENter string: ");
    scanf("%s", s);

    char post[100];
    char stack[100];
    int top = -1, k = 0;

    for (int i = 0; i < strlen(s); i++)
    {

        if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
        {
            post[k++] = s[i];
        }

        else if (s[i] == '(')
        {
            stack[++top] = s[i];
        }

        else if (s[i] == ')')
        {
            while (top != -1 && stack[top] == ')')
            {
                post[k++] = stack[top--];
            }
            --top;
        }

        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            while (top != 1 && precedence(stack[top]) >= precedence(stack[i]))
            {
                post[k++] = stack[top--];
            }
            stack[++top] = s[i];
        }
    }

    while (top != -1)
    {
        post[k++] = stack[top--];
    }

    post[k] = '\0'; // Null-terminate the postfix expression

    printf("Postfix expression: %s\n", post);
}

int main()
{
}