#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[], int n, int i)
{
    int l=(2*i)+1, r=(2*i)+2, max=i;
    if(l<n && arr[l]>arr[max])
        max=l;
    if(r<n && arr[r]>arr[max])
        max=r;
    if(max!=i)
    {
        swap(&arr[i],&arr[max]);
        heapify(arr,n,max);
    }
}

void heapsort(int arr[], int n)
{
    int i;
    for(i=(n/2)-1; i>=0; i--)
        heapify(arr,n,i);
    for(i=n-1; i>=0; i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
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
    heapsort(arr,n);
    printf("\nThe sorted list is:\n");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
        printf("\n");
    return 0;
}
