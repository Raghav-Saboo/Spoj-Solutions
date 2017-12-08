#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map <int,int> mp;
int main() {
	// your code goes here
	int t,i,n,m,e,c,w=1;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&e);
			mp[e]++;
		}
		c=0;
		for(i=1;i<=n;i++)
		{
			if(mp.find(i)!=mp.end())
			{
				c++;
			}
			else if(mp.find(i+1)!=mp.end())
			{
				c++;
			}
			else if(mp.find(i-1)!=mp.end())
			{
				c++;
			}
		}
		printf("Case %d: %d\n",w,c);
		w++;
		mp.clear();
	}
	return 0;
} 