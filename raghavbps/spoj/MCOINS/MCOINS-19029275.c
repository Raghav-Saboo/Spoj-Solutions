#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
void pre(int k,int l)
{
	memset(dp,-1,sizeof(dp));
	int i,mx;
	mx=max(k,l);
	dp[1]=1;
	dp[k]=1;
	dp[l]=1;
	for(i=2;i<=1e6;i++)
	{
		if(dp[i]==-1)
		{
			if((i-1)>=1&&dp[i-1]==0)
			{
				dp[i]=1;
			}
			else if((i-l)>=1&&dp[i-l]==0)
			{
				dp[i]=1;
			}
			else if((i-k)>=1&&dp[i-k]==0)
			{
				dp[i]=1;
			}
			else
			{
				dp[i]=0;
			}
		}
	}
}
int main() {
	// your code goes here
	int n,k,l,m,i;
	cin>>k>>l>>m;
	pre(k,l);
	for(i=1;i<=m;i++)
	{
		cin>>n;
		if(dp[n])
		{
			cout<<"A";
		}
		else
		{
			cout<<"B";
		}
	}
	return 0;
}