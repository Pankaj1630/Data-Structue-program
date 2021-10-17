#include <stdio.h>
void print(int arr[], int n)
{
    int i;
    printf("Printing the values:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int n)
{
    int i, j, small, temp;
    for (i = 0; i < n - 1; i++)
    {
        small = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[small])
            {
                small = j;
            }
        }
        temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n, i, arr[100];
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter the element of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting:\n");
    print(arr, n);
    printf("Array after the sorting;\n");
    selection_sort(arr, n);
    print(arr, n);
    return 0;
}