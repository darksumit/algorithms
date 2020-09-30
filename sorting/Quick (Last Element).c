#include <stdio.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int p,int q)
{
    int x=arr[q];
    int i=p-1,j;
    for(j=p;j<q;j++)
    {
        if(arr[j]<x)
        {
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[q]);
    return i+1;
}

void quicksort(int arr[],int p,int q)
{
    if(p<q)
    {
        int r=partition(arr,p,q);
        quicksort(arr,p,r-1);
        quicksort(arr,r+1,q);
    }
}

int main()
{
    int i,n,arr[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("\nEnter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,n-1);
    printf("\nThe sorted list is:\n");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
    return 0;
}
