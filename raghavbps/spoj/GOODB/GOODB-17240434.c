#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
long int m=1e9+7;
lli mexp(lli a,lli b)
{
	if(b==0)
	{
		return 1;
	}
	lli t=mexp(a,b/2);
	if(b%2==0)
	{
		return (t%m*t%m)%m;
	}
	else
	{
		return ((t%m*t%m)%m*a%m)%m;
	}
}
int main() {
	// your code goes here
	lli i,n,t,w,r;
	cin>>n>>w>>t>>r;
	lli ans=1,dn=1,f=w+r;
	for(i=1;i<=n;i++)
	{
		ans*=i;
		ans%=m;
	}
	for(i=1;i<=t;i++)
	{
		dn*=mexp(i,m-2);
		dn%=m;
	}
	for(i=1;i<=r;i++)
	{
		dn*=mexp(i,m-2);
		dn%=m;
	}
	for(i=1;i<=w;i++)
	{
		dn*=mexp(i,m-2);
		dn%=m;
	}
	ans=((ans%m)*(dn%m))%m;
	cout<<ans<<endl;
	return 0;
}