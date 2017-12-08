#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define sc(x) scanf("%lld",&x)
lli d[105][105];
void fw(lli n)
{
	lli i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(d[i][j]>d[i][k]+d[k][j])
				{
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
}
int main() {
	// your code goes here
	lli n,c,r,i,u,v,w,j,sr,k,tes=1;
	lli ans=0;
	string s,ds,ts;
	vector <string> vs;
	map <string,lli> mp;
	while(1)
	{
		sc(n);
		sc(c);
		sc(r);
		if(!n&&!c&&!r)
		{
			break;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				d[i][j]=1e15;
			}
		}
		k=0;
		cin>>s;
		mp[s]=++k;
		sr=k;
		for(i=2;i<=c+1;i++)
		{
			cin>>s;
			vs.push_back(s);
		}
		while(r--)
		{
			cin>>s>>ts>>ds;
			if(mp.find(s)==mp.end())
			{
				mp[s]=++k;
			//	cout<<s<<" "<<mp[s]<<endl;
			}
			if(mp.find(ds)==mp.end())
			{
				mp[ds]=++k;
			//	cout<<ds<<" "<<mp[ds]<<endl;
			}
			u=mp[s];
			v=mp[ds];
			w=0;
			for(i=2;i<ts.size();i++)
			{
				if(ts[i]>=48&&ts[i]<=57)
				{
					w*=10;
					w+=ts[i]-'0';
				}
			}
			if(ts[0]=='<'&&ts[ts.size()-1]=='>')
			{
				d[u][v]=min(d[u][v],w);
				d[v][u]=min(d[v][u],w);
			}
			else if(ts[0]=='<')
			{
				d[v][u]=min(d[v][u],w);
			}
			else
			{
				d[u][v]=min(d[u][v],w);
			}
		}
		fw(n);
		ans=0;
		for(i=0;i<vs.size();i++)
		{
			ans+=d[sr][mp[vs[i]]]+d[mp[vs[i]]][sr];
			//cout<<vs[i]<<" "<<mp[vs[i]]<<" "<<sr<<endl;
		}
		printf("%lld. %lld\n",tes,ans);
		tes++;
		vs.clear();
		mp.clear();
	}
	return 0;
}