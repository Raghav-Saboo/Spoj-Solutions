#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int rec(int n,int m)
{
	int i,j,c;
	for(i=1;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c=1e7;
			if((j-1)>0)
			{
				c=min(c,dp[i-1][j-1]);
			}
			if((j+1)<m)
			{
				c=min(c,dp[i-1][j+1]);
			}
			c=min(c,dp[i-1][j]);
			dp[i][j]+=c;
		}
	}
	c=1e7;
	for(i=0;i<m;i++)
	{
		c=min(c,dp[n-1][i]);
	}
	return c;
}
int main() {
	// your code goes here
	int n,m,i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>dp[i][j];
		}
	}
	cout<<rec(n,m);
	return 0;
}