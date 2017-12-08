#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100005],lis[100005];
int mp[1000005];
int main()
{
    memset(mp,-1,sizeof(mp));
    int n,i,x,y,ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        lis[i]=1;
        cin>>a[i];
    }
    ans=1;
    mp[a[0]]=0;
    for(i=1;i<n;i++)
    {
        if(mp[a[i]-1]!=-1)
        {
            lis[i]=lis[mp[a[i]-1]]+1;
        }
        mp[a[i]]=i;
    }
    for(i=0;i<n;i++)
    {
        ans=max(ans,lis[i]);
    }
    cout<<ans;
    return 0;
}
