#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,double>
int st[500];
double pd[500],d[500];
vector <pii> ve[500];
double ans;
int sum;
struct cmp
{
	bool operator()(const pii&a,const pii&b)
	{
		return a.second<b.second;
	}
};
priority_queue<pii,vector<pii>,cmp> pq;
void dij(int n,int s)
{
	int i,z,u,t;
	double y;
	for(i=1;i<=n;i++)
	{
		d[i]=10001.0;
		st[i]=0;
		pd[i]=0.0;
	}
	pd[s]=1.0;
	pq.push(pii(s,pd[s]));
	while(!pq.empty())
	{
		t=pq.top().first;
		pq.pop();
		st[t]=1;
		for(i=0;i<ve[t].size();i++)
		{
			u=ve[t][i].first;
			y=ve[t][i].second;
			if(st[u]==0&&pd[t]*y>pd[u])
			{
			    //cout<<y<<endl;
				d[u]=d[t]+y;
				pd[u]=pd[t]*y;
				pq.push(pii(u,pd[u]));
			}
		}
	}
}
int main() {
	// your code goes here
	int n,m,i,u,v;double w;
	//float ans;
	while(1)
	{
		cin>>n;
		if(n==0)
		{
			break;
		}
		cin>>m;
		for(i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			//w=100.0-w;
			w/=100.0;
			ve[u].push_back(pii(v,w));
			ve[v].push_back(pii(u,w));
		}
		v=n;
		ans=1.0;
		dij(n,1);
		for(i=1;i<=n;i++)
		{
		 //   cout<<"1 "<<i<<" "<<pd[i]<<endl;
		}
		for(i=1;i<=n;i++)
		{
			ve[i].clear();
		}
		ans*=pd[n];
		ans*=100.0;
		printf("%.6lf percent\n",ans);
	}
	return 0;
}