#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector <pii> v[65];
int arr[65][65];
int d[65];
int vis[65];
int par[65];
int color[65];
map <int,pair<int,int>> mp;
struct cmp
{
	bool operator()(const pii &a,const pii &b)
	{
		return a.second>b.second;
	}
};
priority_queue <pii,vector<pii>,cmp> pq;
void bfs(int s)
{
	int n=64;
	int i,x,y,z;
	for(i=0;i<n;i++)
	{
		d[i]=1e8;
		color[i]=0;
	}
	d[s]=0;
	par[s]=-1;
	pq.push(make_pair(s,0));
	while(!pq.empty())
	{
		x=pq.top().first;
		pq.pop();
		color[x]=1;
		for(i=0;i<v[x].size();i++)
		{
			y=v[x][i].first;
			z=v[x][i].second;
			if(!color[y]&&d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				par[y]=x;
				pq.push(make_pair(y,d[y]));
			}
		}
	}
}
void pp(int s,int v)
{
	if(s==v)
	{
		cout<<mp[s].first<<" "<<mp[s].second<<" "<<d[v]<<endl;
	}
	else
	{
		pp(s,par[v]);
		cout<<mp[v].first<<" "<<mp[v].second<<" "<<d[v]<<endl;
	}
}
int get(int s,int des)
{
	//cout<<mp[s].first<<" "<<mp[s].second<<endl;
	bfs(s);
	if(d[des]==1e8)
	{
		return -1;
	}
	//pp(s,des);
	return d[des];
}
void pre()
{
	int i,j;
	int x=0;
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			mp[x]=make_pair(i-1,j-1);
			arr[i-1][j-1]=x;
			x++;
		}
	}
	int f;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if((i-1)>=0&&(j+2)<=7)
			{
				f=(i-1)*i+j*(j+2);
				v[arr[i][j]].push_back(make_pair(arr[i-1][j+2],f));
			}
			if((i+1)<=7&&(j+2)<=7)
			{
				f=i*(i+1)+j*(j+2);
				v[arr[i][j]].push_back(make_pair(arr[i+1][j+2],f));
			}
			if((i-2)>=0&&(j+1)<=7)
			{
				f=i*(i-2)+j*(j+1);
				v[arr[i][j]].push_back(make_pair(arr[i-2][j+1],f));
			}
			if((i+2)<=7&&(j+1)<=7)
			{
				f=i*(i+2)+j*(j+1);
				v[arr[i][j]].push_back(make_pair(arr[i+2][j+1],f));
			}
			if((i-2)>=0&&(j-1)>=0)
			{
				f=i*(i-2)+j*(j-1);
				v[arr[i][j]].push_back(make_pair(arr[i-2][j-1],f));
			}
			if((i+2)<=7&&(j-1)>=0)
			{
				f=i*(i+2)+j*(j-1);
				v[arr[i][j]].push_back(make_pair(arr[i+2][j-1],f));
			}
			if((i-1)>=0&&(j-2)>=0)
			{
				f=i*(i-1)+j*(j-2);
				v[arr[i][j]].push_back(make_pair(arr[i-1][j-2],f));
			}
			if((i-1)>=0&&(j+2)<=7)
			{
				f=i*(i-1)+j*(j+2);
				v[arr[i][j]].push_back(make_pair(arr[i-1][j+2],f));
			}
			if((i+1)<=7&&(j-2)>=0)
			{
				f=i*(i+1)+j*(j-2);
				v[arr[i][j]].push_back(make_pair(arr[i+1][j-2],f));
			}
		}
	}
}
int main() {
	// your code goes here
	pre();
	int a,b,c,d;
	while((scanf("%d%d%d%d",&a,&b,&c,&d))!=EOF)
	{
	//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		cout<<get(arr[a][b],arr[c][d])<<endl;
	}
	return 0;
} 