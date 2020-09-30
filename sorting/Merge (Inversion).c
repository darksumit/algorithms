#include <stdio.h>

int merge(int arr[],int p,int q,int r)
{
    int i=p,j=r,k=p,count=0,temp[p+q+1];
    while(i<r && j<=q)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            count+=r-i;
        }
    }
    while(i<r)
        temp[k++]=arr[i++];
    while(j<=q)
        temp[k++]=arr[j++];
    for(i=p;i<=q;i++)
        arr[i]=temp[i];
    return count;
}

int mergesort(int arr[],int p,int q)
{
    int count=0;
    if(p<q)
    {
        int r=(p+q)/2;
        count+=mergesort(arr,p,r);
        count+=mergesort(arr,r+1,q);
        count+=merge(arr,p,q,r+1);
    }
}

int main()
{
    int i,k,n,arr[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("\nEnter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    k=mergesort(arr,0,n-1);
    printf("\nThe sorted list is:\n");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
    printf("Number of inversions: %d\n",k);
    return 0;
}
