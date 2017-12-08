#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
map <int,int> mi;
map <string,int> :: iterator sit;
map <int,int> :: iterator iit;
int main() {
	// your code goes here
	int n,m,i;
	string s;
	while(1)
	{
		cin>>n>>m;
		if(n==0&&m==0)
		{
			break;
		}
		for(i=1;i<=n;i++)
		{
			cin>>s;
			mp[s]++;
			mi[i]=0;
		}
		for(sit=mp.begin();sit!=mp.end();sit++)
		{
			mi[sit->second]++;
		}
		for(iit=mi.begin();iit!=mi.end();iit++)
		{
			cout<<iit->second<<endl;
		}
		mi.clear();
		mp.clear();
	}
	return 0;
}