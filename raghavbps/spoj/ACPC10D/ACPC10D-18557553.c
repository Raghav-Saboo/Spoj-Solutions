#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int dp[1000005][3];
long long int recn(long long int n)
{
	long long int c,i,j,x,a,b,d;
	a=dp[1][0];
	b=dp[1][1];
	d=dp[1][2];
	for(i=0;i<3;i++)
	{
		x=dp[0][1];
		if(i==2||i==1)
		{
			j=dp[0][2]+x;
		}
		else if(i==0)
		{
			j=1e18;
		}
		x=min(x,j);
		dp[1][i]+=x;
	}
	x=dp[1][0]+b;
	dp[1][1]=min(dp[1][1],x);
	x=dp[1][1]+d;
	dp[1][2]=min(dp[1][2],x);
//	cout<<dp[1][0]<<" "<<dp[1][1]<<" "<<dp[1][2]<<endl;
	for(i=2;i<n;i++)
	{
		a=dp[i][0];
		b=dp[i][1];
		d=dp[i][2];
		for(j=0;j<3;j++)
		{
			c=1e7;
			if(j==0)
			{
				x=dp[i-1][j+1];
				c=min(x,dp[i-1][j]);
			}
			else if(j==1)
			{
				x=min(dp[i-1][j-1],dp[i-1][j+1]);
				c=min(x,dp[i-1][j]);
				
			}
			else
			{
				x=dp[i-1][j-1];
				c=min(x,dp[i-1][j]);
			}
			dp[i][j]+=c;
			if(j==1)
			{
				x=dp[i][j-1]+b;
				dp[i][j]=min(dp[i][j],x);
			}
			else if(j==2)
			{
				x=dp[i][j-1]+d;
				dp[i][j]=min(dp[i][j],x);
				x=dp[i][j-1]+d;
				dp[i][j]=min(dp[i][j],x);
			}
		}
	//	cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
	}
	return dp[n-1][1];
}
int main() {
	// your code goes here
	long long int i,j,n,t=1,g;
	while(1)
	{
		cin>>n;
		if(n==0)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				cin>>dp[i][j];
			}
		}
		cout<<t<<". "<<recn(n)<<endl;
		t++;
	}
	return 0;
}