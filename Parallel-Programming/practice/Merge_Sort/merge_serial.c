#include <stdio.h>
#include <omp.h>

void merge(int arr[], int s, int m, int e)
{
    // merging the two sorted array using two pointer approach-:
    int i = s;
    int j = m + 1;
    int c[e + 1];
    int k = s;
    while (i <= m && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            c[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= m)
    {
        c[k] = arr[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (int i = s; i <= e; i++)
    {
       arr[i]=c[i];
    }
}

void mergeSort(int arr[], int s, int e)
{

    int mid = (s + e) / 2;

    if (s >= e)
    {
        return;
    }
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int main()
{
    int n;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("Enter the elements of array\n");
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    double t1=omp_get_wtime();
    mergeSort(arr,0,n-1);
    double t2=omp_get_wtime();
    printf("Serial Execution time is-:%f",(t2-t1));
    printf("\nThe sorted array is-:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}