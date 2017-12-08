#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
#define mp make_pair
vector <pii> v[50005];
int color[50005];
int d[50005];
void bfs(int s,int n)
{
	int i,j,t;pii b;
	for(i=1;i<=n;i++)
	{
		d[i]=-1;
		color[i]=0;
	}
	queue <int> q;
	q.push(s);
	d[s]=0;
	color[s]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<v[t].size();i++)
		{
			b=v[t][i];
			if(color[b.first]==0)
			{
				q.push(b.first);
				d[b.first]=d[t]+b.second;
				color[b.first]=1;
			}
		}
	}
}
int main() {
	// your code goes here
	int ans,i,n,a,b,t,w;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n-1;i++)
		{
			cin>>a>>b>>w;
			v[a].push_back(mp(b,w));
			v[b].push_back(mp(a,w));
		}
		bfs(1,n);
		ans=d[1];
		for(i=1;i<=n;i++)
		{
			if(d[ans]<d[i])
			{
				ans=i;
			}
		}
		bfs(ans,n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans=max(ans,d[i]);
		}
		cout<<ans<<endl;
		for(i=1;i<=n;i++)
		{
			v[i].clear();
		}
	}
	return 0;
}