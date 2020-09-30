#include <stdio.h>

int comp=0,shift=0;

void insertion(int arr[], int n)
{
    int i,j,k;
    for(j=1;j<n;j++)
    {
        i=j-1;
        k=arr[j];
        while(i>=0 && arr[i]>k)
        {
            arr[i+1]=arr[i];
            comp++;
            shift++;
            i=i-1;
        }
        arr[i+1]=k;
        if(i!=-1)
            comp++;
        if(arr[j]!=k)
            shift++;
    }
}

int main()
{
    int i,j,n,arr[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("\nEnter elements in the list:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    insertion(arr,n);
    printf("\nThe sorted list is:\n");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
    printf("Number of comparisons: %d\n",comp);
    printf("Number of shifts: %d\n",shift);
    return 0;
}
