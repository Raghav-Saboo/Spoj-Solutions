#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int coin[5];
int dp[1000005];
int flag;
int memo(int x,int id,int mc,int n)
{
    if(id==-1&&x==0)
    {
        flag=1;
        return 1;
    }
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    int i,f=0,g=0;
    if(id>=0)
    {
        for(i=mc*coin[id];i<=x;i+=coin[id])
        {
            if(x-i>=0)
            {
                //cout<<x-i<<" "<<id-1<<" "<<endl;
                f=memo(x-i,id-1,mc+g,n);
            }
            if(f)
            {
                dp[x]=1;
                return 1;
            }
            g++;
        }
    }
    if(f==0)
    {
        dp[x]=0;
    }
    return 0;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int x,n,i;
    cin>>x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    string s;
    flag=0;
    i=memo(x,n-1,0,n);
    if(flag)
    {
        s="YES";
    }
    else
    {
        s="NO";
    }
    cout<<s;
    return 0;
}
