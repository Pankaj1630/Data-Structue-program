// *************** Insertion sort *********//

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

void insertion(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && key <=a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }   
}
 
int main()
{
    int i, a[100], n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter the element of the array;\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The element before sorting the array:\n");
    print(a, n);
    printf("The array after sorting:\n");
    insertion(a, n);
    print(a, n);
    return 0;
}