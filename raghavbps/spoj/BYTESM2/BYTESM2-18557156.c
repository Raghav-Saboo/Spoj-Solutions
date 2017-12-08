#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
void rec(int h,int w)
{
	int i,j,c;
	for(i=1;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			c=0;
			if((i-1)>=0&&(j-1)>=0)
			{
				c=max(c,dp[i-1][j-1]);
			}
			if((i-1)>=0)
			{
				c=max(c,dp[i-1][j]);
			}
			if((i-1)>=0&&(j+1)<w)
			{
				c=max(c,dp[i-1][j+1]);
			}
			dp[i][j]+=c;
		}
	}
}
int main() {
	// your code goes here
	int t,h,w,j,ans,i;
	cin>>t;
	while(t--)
	{
		cin>>h>>w;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				cin>>dp[i][j];
			}
		}
		rec(h,w);
		ans=0;
		for(i=0;i<w;i++)
		{
			ans=max(ans,dp[h-1][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}