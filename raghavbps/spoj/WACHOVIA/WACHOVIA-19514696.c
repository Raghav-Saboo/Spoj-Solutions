#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1005][55];
int val[55];
int wt[55];
int rec(int kn,int n)
{
    int i,j;
    for(i=0;i<=kn;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(wt[j-1]>i)
            {
                dp[i][j]=dp[i][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],val[j-1]+dp[i-wt[j-1]][j-1]);
            }
        }
    }
    return dp[kn][n];
}
int main()
{
    int t,e,f,x,i;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>e>>f;
        for(i=0;i<f;i++)
        {
            cin>>wt[i]>>val[i];
        }
        cout<<"Hey stupid robber, you can get "<<rec(e,f)<<"."<<endl;
    }
    return 0;
}
