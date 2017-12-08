#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli m=1e9+7;
lli mexp(lli a,lli b)
{
	if(b==0)
	{
		return 1;
	}
	lli t=mexp(a,b/2);
	if(b%2==0)
	{
		return (t*t)%m;
	}
	else
	{
		return ((t*t)%m*(a%m))%m;
	}
}
int main() {
	// your code goes here
	lli t,n,ans,p;
	p=mexp(24,m-2);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=n*(n-1);
		ans%=m;
		ans*=(n-2);
		ans%=m;
		ans*=(n-3);
		ans%=m;
		ans*=p;
		ans%=m;
		cout<<ans<<endl;
	}
	return 0;
}