#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int v[1005];
int memoi(int i,int j)
{
	if(i>j)
	{
		return 0;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	if(j==i)
	{
		return (dp[i][j]=v[i]);
	}
	else if(j==i+1)
	{
		dp[i][j]=max(v[i],v[j]);
		return dp[i][j];
	}
	else
	{
		if(dp[i+2][j]==-1)
		{
			dp[i+2][j]=memoi(i+2,j);
		}
		if(dp[i+1][j-1]==-1)
		{
			dp[i+1][j-1]=memoi(i+1,j-1);
		}
		if(dp[i][j-2]==-1)
		{
			dp[i][j-2]=memoi(i,j-2);
		}
		dp[i][j]=max(v[i]+( (v[i+1]>=v[j]) ? dp[i+2][j] : dp[i+1][j-1]),v[j]+( (v[i]>=v[j-1]) ? dp[i+1][j-1] : dp[i][j-2]));
		return dp[i][j];
	}
}
int main() {
	// your code goes here
	int x,n,i,j,s,k;
	for(k=1;;k++)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				dp[i][j]=-1;
			}
		}
		if(!n)
		{
			break;
		}
		s=0;
		for(i=1;i<=n;i++)
		{
			cin>>v[i];
			s+=v[i];
		}
		x=memoi(1,n);
	//	cout<<x<<endl;
		cout<<"In game "<<k<<", the greedy strategy might lose by as many as "<<x-(s-x)<<" points.\n";
	}
	return 0;
}