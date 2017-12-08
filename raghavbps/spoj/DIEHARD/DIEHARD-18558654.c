#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
void pre()
{
	int i,j;
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=1000;j++)
		{
			dp[i][j]=1;
		}
	}
	int c=0;
	for(i=3;i<=1000;i++)
	{
		for(j=1;j<=1000;j++)
		{
			c=0;
			if((i-2)>0&&(j-8)>0)
			{
				c=max(c,dp[i-2][j-8]);
			}
			if((i-17)>0&&(j+7)<=1000)
			{
				c=max(c,dp[i-17][j+7]);
			}
			if((i-25)>0&&(j-5)>0)
			{
				c=max(c,dp[i-25][j-5]);
			}
			if(c==0)
			{
				dp[i][j]=1;
			}
			else
			{
				dp[i][j]=2+c;
			}
		}
	}
}
int main() {
	// your code goes here
	pre();
	int t,h,a;
	cin>>t;
	while(t--)
	{
		cin>>h>>a;
		cout<<dp[h][a]<<endl;
	}
	return 0;
}