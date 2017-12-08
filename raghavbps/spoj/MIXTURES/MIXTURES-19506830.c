#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[105][105][2];
int arr[105];
int main()
{
    int t,l,i,j,k,n,c;
    while((scanf("%d",&n))!=EOF)
    {
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<n;i++)
        {
            dp[i][i][0]=arr[i];
            dp[i][i][1]=0;
        }
        for(l=2;l<=n;l++)
        {
            for(i=0;i<n-l+1;i++)
            {
                j=i+l-1;
                dp[i][j][1]=INT_MAX;
                for(k=i;k<j;k++)
                {
                    //cout<<i<<" "<<k<<" "<<dp[i][k][0]<<" "<<dp[i][k][1]<<endl;
                    if(dp[i][j][1]>dp[i][k][0]*dp[k+1][j][0]+dp[i][k][1]+dp[k+1][j][1])
                    {
                        dp[i][j][0]=(dp[i][k][0]+dp[k+1][j][0])%100;
                        dp[i][j][1]=dp[i][k][0]*dp[k+1][j][0]+dp[i][k][1]+dp[k+1][j][1];
                    }
                }
            }
        }
        cout<<dp[0][n-1][1]<<endl;
    }
    return 0;
}
