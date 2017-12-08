#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int arr[1005];
int rec(int id,int w,int n)
{
    if(id>=n)
    {
        return 0;
    }
    if(dp[id][w]!=-1)
    {
        return dp[id][w];
    }
    int c=0;
    if(w>=arr[id])
    {
        c=arr[id]+rec(id+2,w-arr[id],n);
    }
    c=max(c,rec(id+1,w,n));
    dp[id][w]=c;
    return dp[id][w];
}
int main()
{
    int p,t,n,m,i;
    cin>>t;
    for(p=1;p<=t;p++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i-1];
        }
        cout<<"Scenario #"<<p<<": "<<rec(0,m,n)<<endl;
    }
    return 0;
}
