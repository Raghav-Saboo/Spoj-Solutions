#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int u;
	int v;
	int w;
};
int ans;
struct node arr[3000005];
int par[3000005];
void make(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		par[i]=i;
	}
}
int fp(int x)
{
	if(x==par[x])
	{
		return x;
	}
	else
	{
		return par[x]=fp(par[x]);
	}
}
void uni(int x,int y,int w)
{
	int px,py;
	px=fp(x);
	py=fp(y);
	if(px!=py)
	{
		ans+=w;
		par[px]=py;
	}
}
int cmp(struct node a,struct node b)
{
	return a.w<b.w;
}
int main() {
	// your code goes here
	int sz,t,n,m,p,a,b,w,i;
	cin>>t;
	while(t--)
	{
		sz=0;
		cin>>p>>n>>m;
		for(i=1;i<=m;i++)
		{
			cin>>a>>b>>w;
			arr[sz].u=a;
			arr[sz].v=b;
			arr[sz++].w=w;
		}
		sort(arr,arr+sz,cmp);
		ans=0;
		make(n);
		for(i=0;i<sz;i++)
		{
			uni(arr[i].u,arr[i].v,arr[i].w);
		}
		ans*=p;
		cout<<ans<<endl;
	}
	return 0;
}