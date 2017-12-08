#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int adj[105][105],d[105][105];
void fw(int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(adj[i][j]!=0)
			{
				d[i][j]=adj[i][j];
			}
			else
			{
				d[i][j]=1e7;
			}
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main() {
	// your code goes here
	int n,e,t,i,j,m,u,v,w,c=1;
	cin>>n>>e>>t>>m;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		adj[u][v]=w;
	}
	fw(n);
	for(j=1;j<=n;j++)
	{
		if(d[j][e]<=t)
		{
			c++;
		}
	}
	cout<<c<<endl;
	return 0;
}