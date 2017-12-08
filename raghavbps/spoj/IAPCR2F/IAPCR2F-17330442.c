#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int par[1005],bud[1005];
map <int,int> mp;
map <int,int> :: iterator it;
multiset <int> s;
multiset <int> :: iterator st;
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
void uni(int x,int y)
{
	int px,py;
	px=fp(x);
	py=fp(y);
	if(px!=py)
	{
		par[px]=py;
	}
}
int main() {
	// your code goes here
	int t,n,m,x,y,i,ans,p=1;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		make(n);
		for(i=1;i<=n;i++)
		{
			cin>>bud[i];
		}
		while(m--)
		{
			cin>>x>>y;
			uni(x,y);
		}
		for(i=1;i<=n;i++)
		{
			if(i==par[i])
			{
				mp[i]++;
			}
		}
		for(it=mp.begin();it!=mp.end();it++)
		{
			for(i=1;i<=n;i++)
			{
				if(fp(i)==it->first)
				{
					mp[it->first]+=bud[i];
				}
			}
			mp[it->first]-=1;
		}
		cout<<"Case "<<p<<": "<<mp.size()<<endl;
		for(it=mp.begin();it!=mp.end();it++)
		{
			s.insert(it->second);
		}
		for(st=s.begin();st!=s.end();st++)
		{
			cout<<*st<<" ";
		}
		cout<<endl;
		p++;
		mp.clear();
		s.clear();
	}
	return 0;
}