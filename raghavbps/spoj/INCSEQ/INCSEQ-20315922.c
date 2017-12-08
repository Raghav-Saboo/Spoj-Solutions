#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[10005];
int b[10005];
int dp[10005][55];
int bit[55][10005];
int mod=5000000;
void update(int id,int n,int k,int v)
{
    while(id<=n)
    {
        bit[k][id]+=v;
        bit[k][id]%=mod;
        id+=(id&-id);
    }
}
int query(int id,int k)
{
    int s=0;
    while(id>0)
    {
        s=s+bit[k][id];
        s=s%mod;
        id-=(id&-id);
    }
    return s;
}
map <int,int> mp;
int main() {
	// your code goes here
	int n,k,i,x,j,p;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
	    scanf("%d",&arr[i]);
	    b[i]=arr[i];
	}
	sort(b+1,b+1+n);
	x=0;
	for(i=1;i<=n;i++)
	{
	    if(mp.find(b[i])==mp.end())
	    {
	        mp[b[i]]=++x;
	    }
	}
	for(i=1;i<=n;i++)
	{
	    arr[i]=mp[arr[i]];
	    dp[i][1]++;
	}
	for(p=2;p<=k;p++)
	{
	    for(i=2;i<=n;i++)
	    {
	        update(arr[i-1],x,p,dp[i-1][p-1]);
	        dp[i][p]+=query(arr[i]-1,p);
	        dp[i][p]%=mod;
	    }
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
	    ans=ans+dp[i][k];
	    ans=ans%mod;
	}
	printf("%d\n",ans);
	return 0;
}
