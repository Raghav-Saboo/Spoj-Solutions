#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int dp[10][70];
long long int rec(long long int n)
{
	long long int i,j,x;
	for(i=0;i<=9;i++)
	{
		dp[i][1]=1;
	}
	for(x=0;x<=9;x++)
	{
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=x;j++)
			{
				dp[x][i]+=dp[j][i-1];
			}
		}
	}
	long long int ans=0;
	for(i=0;i<10;i++)
	{
		ans+=dp[i][n];
	}
	return ans;
}
int main() {
	// your code goes here
	long long int i,t,n,x;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>x>>n;
		cout<<x<<" "<<rec(n)<<endl;
	}
	return 0;
}