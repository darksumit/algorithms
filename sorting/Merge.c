#include <stdio.h>

void merge(int arr[],int p,int q,int r)
{
    int i,j,k;
    int l=r-p+1,m=q-r;
    int left[l],right[m];
    for(i=0;i<l;i++)
        left[i]=arr[p+i];
    for(j=0;j<m;j++)
        right[j]=arr[r+j+1];
    i=0,j=0,k=p;
    while(i<l && j<m)
    {
        if(left[i]<right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<l)
        arr[k++]=left[i++];
    while(j<m)
        arr[k++]=right[j++];
}

void mergesort(int arr[],int p,int q)
{
    if(p<q)
    {
        int r=(p+q)/2;
        mergesort(arr,p,r);
        mergesort(arr,r+1,q);
        merge(arr,p,q,r);
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
    mergesort(arr,0,n-1);
    printf("\nThe sorted list is:\n");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
    return 0;
}
