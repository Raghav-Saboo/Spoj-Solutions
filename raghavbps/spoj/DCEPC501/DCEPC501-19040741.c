#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli v[100005],dp[100005];
lli memo(lli i,lli j)
{
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	if(i>j)
	{
		return (dp[i]=0);
	}
	else if(j-i<=2)
	{
		lli c,x=0;
		for(c=i;c<=j;c++)
		{
			x+=v[c];
		}
		return (dp[i]=x);
	}
	else
	{
		return (dp[i]=max(max(v[i]+memo(i+2,j),v[i]+v[i+1]+memo(i+4,j)),v[i]+v[i+1]+v[i+2]+memo(i+6,j)));
	}
}
int main() {
	// your code goes here
	lli t,n,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		memset(dp,-1,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&v[i]);
		}
		printf("%lld\n",memo(1,n));
	}
	return 0;
}