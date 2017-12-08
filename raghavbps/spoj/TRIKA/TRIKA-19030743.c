#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[25][25];
int main() {
	// your code goes here
	int n,m,i,j,x,y;
	cin>>n>>m>>x>>y;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>dp[i][j];
		}
	}
	int flag;
	for(i=n;i>=1;i--)
	{
		for(j=m;j>=1;j--)
		{
			int mn=INT_MAX;
			if((j+1)<=m)
			{
				mn=min(mn,dp[i][j+1]);
			}
			if((i+1)<=n)
			{
				mn=min(mn,dp[i+1][j]);
			}
			if(i==x&&j==y)
			{
				if(dp[i][j]>=mn&&mn!=INT_MAX)
				{
					cout<<"Y "<<dp[i][j]-mn<<endl;
				}
				else
				{
					cout<<"N"<<endl;
				}
			}
			if(mn!=INT_MAX)
			{
				dp[i][j]+=mn;
			}
		}
	}
	return 0;
}