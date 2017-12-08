#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
map <lli,lli> mp;
lli rec(lli n)
{
	if(mp.find(n)!=mp.end())
	{
		return mp[n];
	}
	else
	{
		lli x=rec(n/2)+rec(n/3)+rec(n/4);
		mp[n]=max(n,x);
		return mp[n];
	}
}
int main() {
	// your code goes here
	lli i,n;
	for(i=0;i<=5;i++)
	{
		mp[i]=i;
	}
	while( scanf("%lld", &n) != EOF)
	{
		cout<<rec(n)<<endl;
	}
	return 0;
}