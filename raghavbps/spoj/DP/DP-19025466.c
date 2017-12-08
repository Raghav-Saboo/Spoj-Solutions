#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
vector <pii> v[2600];
char adj[55][55];
int vl[55][55],fans;
int des[30],ans[30];
struct cmp
{
	bool operator()(const pii &a,const pii &b)
	{
		return a.second>b.second;
	}
};
priority_queue <pii,vector<pii>,cmp> pq;
int d[2600],color[2600];
void dij(int s,int n)
{
	int i,x,y;
	for(i=1;i<=n;i++)
	{
		d[i]=INT_MAX;
		color[i]=0;
	}
	d[s]=0;
	pq.push(mp(s,0));
	while(!pq.empty())
	{
		x=pq.top().first;
		y=pq.top().second;
	//	cout<<x<<" "<<y<<endl;
		pq.pop();
		color[x]=1;
		for(i=0;i<v[x].size();i++)
		{
			if(color[v[x][i].first]==0&&d[v[x][i].first]>y+v[x][i].second)
			{
				d[v[x][i].first]=y+v[x][i].second;
			//	cout<<v[x][i].first<<" "<<d[v[x][i].first]<<endl;
				pq.push(mp(v[x][i].first,d[v[x][i].first]));
			}
		}
	}
}
void rec(int a[],int id,int n)
{
	if(id==n+1)
	{
		int i,x=0,y=0,mx1=0,mx2=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				mx1=max(mx1,ans[i]);
				x+=2*ans[i];
			}
			else
			{
				mx2=max(mx2,ans[i]);
				y+=2*ans[i];
			}
		}
		x-=mx1;
		y-=mx2;
		fans=min(fans,max(x,y));
	}
	else
	{
		a[id+1]=0;
		rec(a,id+1,n);
		a[id+1]=1;
		rec(a,id+1,n);
	}
}
int main() {
	// your code goes here
	int sz,t,m,n,i,j,k,s;
	char c;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		k=0;sz=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>adj[i][j];
				vl[i][j]=++k;
				if(adj[i][j]=='$')
				{
					des[++sz]=k;
				}
				else if(adj[i][j]=='X')
				{
					s=k;
				}
			}
		}
		//cout<<sz<<" "<<s<<endl;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(adj[i][j]>=48&&adj[i][j]<=57)
				{
					if((i-1)>=1&&(adj[i-1][j]=='$'||adj[i-1][j]=='X'))
					{
						v[vl[i][j]].pb(mp(vl[i-1][j],2));
					}
					else if((i-1)>=1&&adj[i-1][j]>=48&&adj[i-1][j]<=57&&abs(adj[i-1][j]-adj[i][j])<=1)
					{
						if(abs(adj[i-1][j]-adj[i][j])==1)
						{
							v[vl[i][j]].pb(mp(vl[i-1][j],3));
						}
						else
						{
							v[vl[i][j]].pb(mp(vl[i-1][j],1));
						}
					}
					if((j-1)>=1&&(adj[i][j-1]=='$'||adj[i][j-1]=='X'))
					{
						v[vl[i][j]].pb(mp(vl[i][j-1],2));
					}
					else if((j-1)>=1&&adj[i][j-1]>=48&&adj[i][j-1]<=57&&abs(adj[i][j-1]-adj[i][j])<=1)
					{
						if(abs(adj[i][j-1]-adj[i][j])==1)
						{
							v[vl[i][j]].pb(mp(vl[i][j-1],3));
						}
						else
						{
							v[vl[i][j]].pb(mp(vl[i][j-1],1));
						}
					}
					if((i+1)<=m&&(adj[i+1][j]=='$'||adj[i+1][j]=='X'))
					{
						v[vl[i][j]].pb(mp(vl[i+1][j],2));
					}
					else if((i+1)<=m&&adj[i+1][j]>=48&&adj[i+1][j]<=57&&abs(adj[i+1][j]-adj[i][j])<=1)
					{
						if(abs(adj[i+1][j]-adj[i][j])==1)
						{
							v[vl[i][j]].pb(mp(vl[i+1][j],3));
						}
						else
						{
							v[vl[i][j]].pb(mp(vl[i+1][j],1));
						}
					}
					if((j+1)<=n&&(adj[i][j+1]=='$'||adj[i][j+1]=='X'))
					{
						v[vl[i][j]].pb(mp(vl[i][j+1],2));
					}
					else if((j+1)<=n&&adj[i][j+1]>=48&&adj[i][j+1]<=57&&abs(adj[i][j+1]-adj[i][j])<=1)
					{
						if(abs(adj[i][j+1]-adj[i][j])==1)
						{
							v[vl[i][j]].pb(mp(vl[i][j+1],3));
						}
						else
						{
							v[vl[i][j]].pb(mp(vl[i][j+1],1));
						}
					}
				}
				else
				{
					if((i-1)>=1)
					{
						v[vl[i][j]].pb(mp(vl[i-1][j],2));
					}
					if((j-1)>=1)
					{
						v[vl[i][j]].pb(mp(vl[i][j-1],2));
					}
					if((i+1)<=m)
					{
						v[vl[i][j]].pb(mp(vl[i+1][j],2));
					}
					if((j+1)<=n)
					{
						v[vl[i][j]].pb(mp(vl[i][j+1],2));
					}
				}
			}
		}
		dij(s,k);
		int n=0,a[30];
		for(i=1;i<=sz;i++)
		{
			if(d[des[i]]==INT_MAX)
			{
				i=-1;
				cout<<"-1\n";
				break;
			}
			else
			{
			//	cout<<d[des[i]]<<" ";
				ans[++n]=d[des[i]];
				a[n]=0;
			}
		}
		if(i!=-1)
		{
			fans=INT_MAX;
			a[1]=0;
			rec(a,1,n);
			a[1]=1;
			rec(a,1,n);
			cout<<fans<<endl;
		}
		for(i=1;i<=k;i++)
		{
			v[i].clear();
		}
	}
	return 0;
}