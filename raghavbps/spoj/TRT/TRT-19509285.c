#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int v[2005];
int dp[2005][2005];
int memo(int i,int j,int a)
{
    if(j<i)
    {
        return 0;
    }
    if(i==j)
    {
        return v[i]*a;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int c;
    c=max(a*v[i]+memo(i+1,j,a+1),a*v[j]+memo(i,j-1,a+1));
    dp[i][j]=c;
    //cout<<c<<" ";
    return dp[i][j];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<memo(0,n-1,1);
    return 0;
}
