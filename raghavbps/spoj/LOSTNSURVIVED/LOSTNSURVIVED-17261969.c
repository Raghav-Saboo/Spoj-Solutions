#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int par[100005],siz[100005];
multiset <int> se;
multiset <int> :: reverse_iterator rit;
multiset <int> :: iterator it;
void ms(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		siz[i]=1;
		se.insert(siz[i]);
		par[i]=i;
	}
}
int fp(int x)
{
	if(par[x]==x)
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
	if(par[px]!=py)
	{
		par[px]=py;
		se.erase(se.find(siz[px]));
		se.erase(se.find(siz[py]));
		siz[py]+=siz[px];
		se.insert(siz[py]);
	}
}
int main() {
	// your code goes here
	int n,q,u,v,ans;
	scanf("%d%d",&n,&q);
	ms(n);
	while(q--)
	{
		scanf("%d%d",&u,&v);
		uni(u,v);
		rit=se.rbegin();
		it=se.begin();
		ans=*rit-*it;
		printf("%d\n",ans);
	}
	return 0;
}