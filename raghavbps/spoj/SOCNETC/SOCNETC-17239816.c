#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m,siz[100005],par[100005];
void ms(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		par[i]=i;
		siz[i]=1;
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
void uni(int x,int y)
{
	int px,py;
	px=fp(x);
	py=fp(y);
	if(px!=py&&((siz[py]+siz[px])<=m))
	{
		par[px]=py;
		siz[py]+=siz[px];
		siz[px]=siz[py];
	}
}
int main() {
	// your code goes here
	int n,q,x,y;
	char ch;
	cin>>n>>m;
	cin>>q;
	ms(n);
	while(q--)
	{
		cin>>ch;
		if(ch=='A')
		{
			cin>>x>>y;
			uni(x,y);
		}
		else if(ch=='E')
		{
			cin>>x>>y;
			if(fp(x)==fp(y))
			{
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
		else
		{
			cin>>x;
			cout<<siz[fp(x)]<<endl;
		}
	}
	return 0;
} 