#include <stdio.h>

void merge(int arr[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int left_array[n1], right_array[n2];
    for (i = 0; i < n1; i++)
    {
        left_array[i] = arr[beg + i];
    }

    for (j = 0; j < n2; j++)
    {
        right_array[j] = arr[mid + 1 + j];
    }
    i = 0, j = 0, k = beg;
    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

void display(int arr[],int n)
{
    int i;
    printf("Printing the elements ");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, arr[100], i;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    printf("Enter the element of the array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Element before sorting \n");
    display(arr,n);
    printf("Element after sorting the element\n");
    merge_sort(arr,0,n-1);
    display(arr,n);
    return 0;
}