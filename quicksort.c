#include <stdio.h>;
#include <stdlib.h>;

static int partition(int a[], int low, int high)
{
    // set the pivot element to the highese(rightmost) element
    int pivot = a[high];
    int i = low;

    for (int j = 0; j < high; ++j)
    {
        if (a[j] < pivot) // if a number is less than the pivot we swith the lowest index and that number
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            ++i;
        }
    }

    // then we switch ith element with high i.e. our pivot
    int temp = a[i];
    a[i] = a[high];
    a[high] = temp;

    return i;
}

static void quick_sort(int a[], int low, int high)
{

    if (low >= high)
        return;

    int p = partition(a, low, high);
    quick_sort(a, 0, p - 1);
    quick_sort(a, p + 1, high);
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        fprintf(stderr, "Invalid n\n");
        return EXIT_FAILURE;
    }

    int *arr = malloc(sizeof(int) * n);
    if (!arr)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; ++i)
        if (scanf("%d", &arr[i]) != 1)
        {
            fprintf(stderr, "Invalid input\n");
            free(arr);
            return EXIT_FAILURE;
        }

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
        printf("%d%c", arr[i], i + 1 == n ? '\n' : ' ');

    free(arr);
    return EXIT_SUCCESS;
}
