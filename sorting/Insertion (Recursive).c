#include <stdio.h>

void recursive(int arr[],int n)
{
    if(n==1)
        return;
    recursive(arr,n-1);
    int i,j,k;
    j=n-1;
    i=j-1;
    k=arr[j];
    while(i>=0 && arr[i]>k)
    {
        arr[i+1]=arr[i];
        i=i-1;
    }
    arr[i+1]=k;
}
int main()
{
    int i,n,arr[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("\nEnter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    recursive(arr,n);
    printf("\nThe sorted list is:\n");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
    return 0;
}
