#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lint long long int
lint dp[100005];
lint tmp[100005];
lint arr[100005];
lint rec(lint n)
{
    lint i,mx;
    dp[1]=arr[1];
    dp[2]=arr[2];
    mx=dp[1];
    for(i=3;i<=n;i++)
    {
        dp[i]=arr[i]+mx;
        mx=max(mx,dp[i-1]);
    }
    mx=0;
    for(i=1;i<=n;i++)
    {
        mx=max(mx,dp[i]);
    }
    return mx;
}
int main()
{
    lint m,n,i,c,j;
    while(1)
    {
        cin>>m>>n;
        if(m==0||n==0)
        {
            break;
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>arr[j];
            }
            tmp[i]=rec(n);
        }
        for(i=1;i<=m;i++)
        {
            arr[i]=tmp[i];
        }
        cout<<rec(m)<<endl;
    }
    return 0;
}
