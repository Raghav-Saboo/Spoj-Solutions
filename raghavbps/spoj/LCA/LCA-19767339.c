#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mx 15
int lev[1005],vis[1005],par[1005];
int dp[1005][mx];
vector <int> v[1005];
void dfs(int u,int l,int p)
{
	par[u]=p;
	vis[u]=1;
	lev[u]=l;
	for(int i=0;i<v[u].size();i++)
	{
		if(!vis[v[u][i]])
		{
			dfs(v[u][i],l+1,u);
		}
	}
}
void pre(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=0;(1<<j)<n;j++)
		{
			dp[i][j]=-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		dp[i][0]=par[i];
	}
	for(j=1;(1<<j)<n;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(dp[i][j-1]!=-1)
			{
				dp[i][j]=dp[dp[i][j-1]][j-1];
			}
		}
	}
}
int query(int n,int p,int q)
{
	int tmp,Log,i;
	if(lev[p]<lev[q])
	{
		tmp=p;
		p=q;
		q=tmp;
	}
	for(Log=1;(1<<Log)<=lev[p];Log++);
	Log--;
	for(i=Log;i>=0;i--)
	{
		if(lev[p]-(1<<i)>=lev[q])
		{
			p=dp[p][i];
		}
	}
	if(p==q)
	{
		return p;
	}
	//cout<<p<<" "<<q<<endl;
	for(i=Log;i>=0;i--)
	{
		if(dp[p][i]!=-1&&dp[p][i]!=dp[q][i])
		{
			p=dp[p][i];
			q=dp[q][i];
		}
	}
	//cout<<p<<" "<<q<<endl;
	return par[p];
}
int main() {
	// your code goes here
	int t,n,i,m,j,x,y=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>x;
			for(j=1;j<=x;j++)
			{
				cin>>m;
				v[i].push_back(m);
			}
		}
		for(i=1;i<=n;i++)
		{
			lev[i]=0;
			par[i]=-1;
			vis[i]=0;
		}
		dfs(1,0,-1);
		cout<<"Case "<<y<<":\n";
		int q;
		cin>>q;
		pre(n);
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			cout<<query(n,a,b)<<endl;
		}
		for(i=1;i<=n;i++)
		{
			v[i].clear();
		}
		y++;
	}
	return 0;
} 