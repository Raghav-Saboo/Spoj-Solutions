#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector <int> adj[1005];
vector <int> radj[1005];
int vis[1005];
pii arr[1005];
set <pii> lst;
int rnk[1005];
int cmp(pii a,pii b)
{
	if(a.first!=b.first)
	{
		return a.first<b.first;
	}
	return a.second<b.second;
}
void dfs(int u,stack <int> &s)
{
	vis[u]=1;
	int i;
	for(i=0;i<adj[u].size();i++)
	{
		if(!vis[adj[u][i]])
		{
			dfs(adj[u][i],s);
		}
	}
	s.push(u);
}
int main()
{
	int t,i,n,m,u,v,ct=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		while(m--)
		{
			scanf("%d%d",&u,&v);
			adj[v].push_back(u);
			radj[u].push_back(v);
			lst.insert(make_pair(v,u));
		}
		stack <int> st;
		for(i=0;i<n;i++)
		{
			vis[i]=0;
		}
		for(i=0;i<n;i++)
		{
			if(!vis[i])
			{
				dfs(i,st);
			}
		}
		int c=0,r=0,pv=-1;
		while(!st.empty())
		{
			//cout<<st.top()<<" ";
			arr[c].second=st.top();
			r=0;
			for(i=0;i<radj[arr[c].second].size();i++)
			{
				r=max(r,rnk[radj[arr[c].second][i]]);
			}
			arr[c].first=r+1;
			rnk[arr[c].second]=r+1;
			c++;
			st.pop();
		}
		//cout<<endl;
		sort(arr,arr+c,cmp);
		printf("Scenario #%d:\n",ct);
		for(i=0;i<c;i++)
		{	
			printf("%d %d\n",arr[i].first,arr[i].second);
		}
		//printf("\n");
		for(i=0;i<n;i++)
		{
			adj[i].clear();
			radj[i].clear();
		}
		ct++;
		lst.clear();
	}
	return 0;
}


