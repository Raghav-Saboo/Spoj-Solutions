#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[100005][105];
int a[105];
int main()
{
    int t,n,i,j,s,x;
    int ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        s=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        for(i=0;i<=s;i++)
        {
            for(j=0;j<n;j++)
            {
                dp[i][j]=0;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                dp[a[i]][j]=1;
            }
        }
        for(i=1;i<=s;i++)
        {
            for(j=0;j<n;j++)
            {
                if(!dp[i][j]&&j>=1&&i-a[j]>=0)
                {
                    dp[i][j]=dp[i-a[j]][j-1]||dp[i][j-1];
                }   
                else if(!dp[i][j]&&j>=1)
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        ans=0;
        for(i=1;i<=s;i++)
        {
            x=0;
            for(j=0;j<n;j++)
            {
                if(dp[i][j])
                {
                    x=1;
                    break;
                }
            }
            if(x)
            {
                ans+=i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
