#include <stdio.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int p, int q)
{
    int x=arr[p];
    int i=p,j;
    for(j=p+1;j<=q;j++)
    {
        if(arr[j]>x)
        {
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i],&arr[p]);
    return i;
}

int select(int arr[], int p, int q, int k)
{
    if(k>=0 && k<=q-p+1)
    {
        int r=partition(arr,p,q);
        if(r-p+1>k)
            return select(arr,p,r-1,k);
        else if(r-p+1==k)
            return r;
        return select(arr,r+1,q,k-(r+p+1));
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
    select(arr,0,n-1,0);
    printf("\nThe sorted list is:\n");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
    return 0;
}
