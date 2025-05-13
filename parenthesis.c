#include <stdio.h>;
#include <stdlib.h>;
#include <stdbool.h>;
#include <string.h>;

bool checkMatch(char c1, char c2)
{
    if (c1 == '(' && c2 == ')')
        return true;
    if (c1 == '[' && c2 == ']')
        return true;
    if (c1 == '{' && c2 == '}')
        return true;
    return false;
}

void isBalanced()
{
    char s[100];
    printf("enter the string: ");
    scanf("%s", s);

    int top = -1;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (top < 0 || !checkMatch(s[top], s[i]))
        {
            ++top;
            s[top] = s[i];
        }
        else
        {
            --top;
        }
    }

    if (top == -1)
    {
        printf("The string is balanced");
    }
}

int main()
{
    isBalanced();
}