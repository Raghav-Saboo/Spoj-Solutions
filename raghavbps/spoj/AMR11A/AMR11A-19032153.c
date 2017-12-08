#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int memo(int n,int m)
{
	int i,j;
	for(i=n;i>=1;i--)
	{
		for(j=m;j>=1;j--)
		{
			if(i==n&&j==m)
			{
				dp[i][j]=1;
			}
			else
			{
				int mn=INT_MAX;
				if(dp[i][j]>=0)
				{
					if((i+1)<=n)
					{
						mn=min(mn,dp[i+1][j]);	
					}
					if((j+1)<=m)
					{
						mn=min(mn,dp[i][j+1]);
					}
					dp[i][j]=max(1,mn-dp[i][j]);
				}
				else
				{
					if((i+1)<=n)
					{
						mn=min(mn,dp[i+1][j]);	
					}
					if((j+1)<=m)
					{
						mn=min(mn,dp[i][j+1]);
					}
					dp[i][j]=max(1,mn-dp[i][j]);
				}
			}
		}
	}
	return abs(dp[1][1]);
}
int main() {
	// your code goes here
	int t,n,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>dp[i][j];
			}
		}
		cout<<memo(n,m)<<endl;
	}
	return 0;
}