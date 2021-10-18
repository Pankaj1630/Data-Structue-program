#include <stdio.h>

void quick_sort(int arr[], int start, int end)
{
    int i, j, pivot, temp;
    if (start < end)
    {
        pivot = start;
        i = start;
        j = end;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && arr[i] < end)
            {
                i++;
            }
            while (arr[j] > arr[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = arr[pivot];
        quick_sort(arr, start, j - 1);
        quick_sort(arr, j + 1, end);
    }
}

void display(int arr[100],int n)
{
    
    printf("Printing the elemetn...\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[100], i, n;
    printf("Enter size of the array you want to sort:\n");
    scanf("%d", &n);
    printf("Enter the element of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Element before sorting\n");
    display(arr, n);
    quick_sort(arr, 0, n - 1);
    printf("Element after sorting \n");
    display(arr, n);
    return 0;
}