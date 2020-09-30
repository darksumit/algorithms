#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

void knapsack(int W,int val[],int wt[],int n)
{
    int i,j,k=0,dp[W+1][n+1];
    memset(dp,0,sizeof(dp));

    for(i=0;i<n;i++)
    {
        if(wt[i]==W)
            k=1;
    }

    for(i=0;i<=W;i++)
    {
        for(j=0;j<=n;j++)
        {
            if (i==0 || j==0)
                dp[i][j]=0;
            else
            {
                dp[i][j]=dp[i-wt[j-1]][j]+val[j-1];
                if(wt[j-1]<=i && dp[i][j-1])
                    dp[i][j]=min(dp[i][j-1],dp[i-wt[j-1]][j]+val[j-1]);
            }
        }
    }

    /*for(i=0;i<=W;i++)
    {
        for(j=0;j<=n;j++)
            printf("%d\t",dp[i][j]);
        printf("\n");
    }*/

    if (dp[W][n]==dp[W-1][n] && k==0)
        printf("This is impossible.\n");
    else
        printf("The minimum amount of money in the piggy-bank is %d.\n",dp[W][n]);
}

int main()
{
    int i,n,t,w,we,wf,val[501],wt[501];
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d",&we);
        scanf("%d",&wf);
        w=wf-we;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&val[i]);
            scanf("%d",&wt[i]);
        }
        knapsack(w,val,wt,n);
        t--;
    }
    return 0;
}
