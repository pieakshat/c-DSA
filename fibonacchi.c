#include <stdio.h>;

void without_recursion(int n)
{
    int a1 = 0;
    int a2 = 1;

    printf("%d ", a1);
    printf("%d ", a2);
    while (a2 < n)
    {
        int temp = a2;
        a2 += a1;
        a1 = temp;
        printf("%d ", a2);
    }
}

int with_recursion(int n)
{
    if (n <= 1)
        return n;

    return with_recursion(n - 1) + with_recursion(n - 2);
}

int main()
{
    // without_recursion(25);
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", with_recursion(i));
    }
}