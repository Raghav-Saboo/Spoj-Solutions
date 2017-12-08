#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char adj[55][55];
int dp[55][55];
int memo(int i,int j,int n,int m)
{
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int mx=0;
    if((i-1)>=0&&adj[i-1][j]==adj[i][j]+1)
    {
        mx=max(mx,memo(i-1,j,n,m));
    }
    if((j-1)>=0&&adj[i][j-1]==adj[i][j]+1)
    {
        mx=max(mx,memo(i,j-1,n,m));
    }
    if((i+1)<n&&adj[i+1][j]==adj[i][j]+1)
    {
        mx=max(mx,memo(i+1,j,n,m));
    }
    if((j+1)<m&&adj[i][j+1]==adj[i][j]+1)
    {
        mx=max(mx,memo(i,j+1,n,m));
    }
    if((i-1)>=0&&(j-1)>=0&&adj[i-1][j-1]==adj[i][j]+1)
    {
        mx=max(mx,memo(i-1,j-1,n,m));
    }
    if((i-1)>=0&&(j+1)<m&&adj[i-1][j+1]==adj[i][j]+1)
    {
        mx=max(mx,memo(i-1,j+1,n,m));
    }
    if((i+1)<n&&(j-1)>=0&&adj[i+1][j-1]==adj[i][j]+1)
    {
        mx=max(mx,memo(i+1,j-1,n,m));
    }
    if((i+1)<n&&(j+1)<m&&adj[i+1][j+1]==adj[i][j]+1)
    {
        mx=max(mx,memo(i+1,j+1,n,m));
    }
    dp[i][j]=1+mx;
    return dp[i][j];
}
int main()
{
    int i,j,n,m,t,x;
    for(x=1;;x++)
    {
        cin>>n>>m;
        if(n==0||m==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>adj[i][j];
            }
        }
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(adj[i][j]=='A')
                {
                    ans=max(ans,memo(i,j,n,m));
                }
            }
        }
        cout<<"Case "<<x<<": "<<ans<<endl;
    }
    return 0;
}
