#include <bits/stdc++.h>
using namespace std;
int par[10005];
void makeset(int n)
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
	return (par[x]=fp(par[x]));
}
void unio(int x,int y,int *flag)
{
	int px,py;
	px=fp(x);
	py=fp(y);
	if(px!=py)
	{
		par[px]=py;
	}
	else
	{
		*flag=1;
	}
}
int main() {
	// your code goes here
	int m,n,u,v,i,flag,x=0,c=0;
	cin>>n>>m;
	makeset(n);
	for(i=1;i<=m;i++)
	{
		flag=0;
		cin>>u>>v;
		unio(u,v,&flag);
		if(flag==1)
		{
			x=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(par[i]==i)
		{
			c++;
		}
	}
	if(x==1||c>1)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
	}
	return 0;
}