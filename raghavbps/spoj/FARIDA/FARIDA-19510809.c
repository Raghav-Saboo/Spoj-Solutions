#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lint long long int
lint dp[10005];
lint arr[10005];
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
    lint t,n,i,p;
    cin>>t;
    for(p=1;p<=t;p++)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        cout<<"Case "<<p<<": "<<rec(n)<<endl;
    }
    return 0;
}
