#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a1[2005],dp[2005][2005],a2[2005];
int lcs(int n,int m)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)
			{
				dp[i][j]=0;
			}
			else if(a1[i-1]==a2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}
int main() {
	// your code goes here
	int t,m,n,x,c,ans;
	cin>>t;
	while(t--)
	{
		ans=0;
		m=0;
		n=0;
		c=1;
		while(1)
		{
			cin>>x;
			if(x==0)
			{
				break;
			}
			if(c==1)
			{
				n=0;
				while(x!=0)
				{
					a1[n++]=x;
					cin>>x;
				}
			}
			else
			{
				m=0;
				while(x!=0)
				{
					a2[m++]=x;
					cin>>x;
				}	
				ans=max(ans,lcs(n,m));	
			}
			c++;
		}
		cout<<ans<<endl;
	}
	return 0;
}