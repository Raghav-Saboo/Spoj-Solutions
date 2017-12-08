#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int pil[10005],asp[10005];
int memo(int i,int j)
{
    if(j==0)
    {
        int x=0;
        int y=0;
        while(x<=i)
        {
            y+=asp[x];
            x++;
        }
        return y;
    }
    if((i+1)<2*j)
    {
        return 1e9*2;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans;
    ans=pil[i]+memo(i-1,j-1);
    ans=min(ans,asp[i]+memo(i-1,j));
    return dp[i][j]=ans;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&pil[i],&asp[i]);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d",pil[n-1]+memo(n-2,(n/2)-1));
    return 0;
} 