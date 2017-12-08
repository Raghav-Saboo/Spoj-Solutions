#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int rec(string a,string b)
{
    int n,m,i,j;
    n=a.size();
    m=b.size();
    for(i=0;i<=m;i++)
    {
        dp[i][0]=i;
    }
    for(i=0;i<=n;i++)
    {
        dp[0][i]=i;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}
int main()
{
    int t;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<rec(a,b)<<endl;
    }
    return 0;
}
