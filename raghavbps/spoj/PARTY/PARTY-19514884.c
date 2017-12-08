#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
pii dp[505][105];
int val[105];
int wt[105];
pii rec(int kn,int n)
{
    int i,j;
    for(i=0;i<=kn;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j].first=0;
                dp[i][j].second=0;
            }
            else if(wt[j-1]>i)
            {
                    dp[i][j].first=dp[i][j-1].first;
                    dp[i][j].second=dp[i][j-1].second;
            }
            else
            {
                if(dp[i][j].first<val[j-1]+dp[i-wt[j-1]][j-1].first)
                {
                    dp[i][j].second=wt[j-1]+dp[i-wt[j-1]][j-1].second;
                    dp[i][j].first=val[j-1]+dp[i-wt[j-1]][j-1].first;
                }
                if(dp[i][j].first<dp[i][j-1].first)
                {
                    dp[i][j].first=dp[i][j-1].first;
                    dp[i][j].second=dp[i][j-1].second;
                }
            }
        }
    }
    return dp[kn][n];
}
int main()
{
    int t,e,f,x,i,j;
    while(1)
    {
        cin>>e>>f;
        if(e==0||f==0)
        {
            break;
        }
        for(i=0;i<=e;i++)
        {
            for(j=0;j<=f;j++)
            {
                dp[i][j].first=dp[i][j].second=0;
            }
        }
        for(i=0;i<f;i++)
        {
            cin>>wt[i]>>val[i];
        }
        pii p=rec(e,f);
        for(i=0;i<=e;i++)
        {
            if(dp[i][f].first==p.first)
            {
                p.second=i;
                break;
            }
        }
        cout<<p.second<<" "<<p.first<<endl;
    }
    return 0;
}
