// ***********Bubble sort**************//
#include <stdio.h>
void print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble(int a[], int n)
{
    int temp, i, j;
    int issort = 0;
    for (i = 0; i < n; i++)
    {
        printf("\nThe number of passes used to sort the array is %d\n ", i + 1);
        issort = 1;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                issort = 0;
            }
        }
        if (issort)
        {
            return;
        }
    }
}

int main()
{
    int i, n, a[100];
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    printf("Enter the element of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The value before sorting the array\n");
    print(a, n);
    printf("The value after sorting the array\n");
    bubble(a, n);
    print(a, n);
    return 0;
}