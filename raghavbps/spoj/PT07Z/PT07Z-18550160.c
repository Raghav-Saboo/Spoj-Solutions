#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[10005];
int d[10005];
int color[10005];
void bfs(int n,int s)
{
	int i,t;
	for(i=1;i<=n;i++)
	{
		d[i]=1e5;
		color[i]=0;
	}
	d[s]=0;
	color[s]=1;
	queue <int> q;
	q.push(s);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<v[t].size();i++)
		{
			if(color[v[t][i]]==0)
			{
				color[v[t][i]]=1;
				d[v[t][i]]=d[t]+1;
				q.push(v[t][i]);
			}
		}
	}
}
int main() {
	// your code goes here
	int n,i,ans,j,a,b;
	cin>>n;
	for(i=1;i<=n-1;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(n,1);
	ans=1;
	for(i=1;i<=n;i++)
	{
		if(d[i]!=1e5&&d[i]>d[ans])
		{
			ans=i;
		}
	}
	bfs(n,ans);
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(d[i]!=1e5)
		{
			ans=max(ans,d[i]);
		}
	}
	cout<<ans;
	return 0;
}