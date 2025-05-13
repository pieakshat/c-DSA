#include <stdio.h>;
#include <stdlib.h>;

// remember, left and right are just index numbers
static void merge(int a[], int left, int mid, int right)
{

    // n1 and n2 are the length of the left and right sections
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // initialising left and right array
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    // filling left and right vector
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    // combining back the left and right vector
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++]; // if left element is bigger than the right one we place left first
    }

    // fill in the rest of the elements
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];

    free(L);
    free(R);
}

static void merge_sort(int a[], int left, int right)
{
    if (left >= right)
        return; // base case

    // find out the midpoint
    int mid = left + (right - left) / 2;

    // recursive calls to the left and right sections
    // Ik this looks weid but remember we have to split the array multiple times
    merge_sort(a, 0, mid);
    merge_sort(a, mid + 1, right);

    // in the end we merge the arrays back
    merge(a, left, mid, right);
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        fprintf(stderr, "Invalid n\n");
        return EXIT_FAILURE;
    }

    int *arr = malloc(n * sizeof(int));
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

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
        printf("%d%c", arr[i], i + 1 == n ? '\n' : ' ');

    free(arr);
    return EXIT_SUCCESS;
}