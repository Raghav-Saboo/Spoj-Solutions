#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
long int m=10000007;
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
	lli n,k,ans;
	while(1)
	{
		cin>>n>>k;
		if(n==0&&k==0)
		{
			break;
		}
		ans=m;
		ans=(ans%m+mexp(n,n))%m;
		ans=(ans%m+(2*mexp(n-1,k))%m)%m;
		ans=(ans%m+(2*mexp(n-1,n-1))%m)%m;
		ans=(ans%m+mexp(n,k))%m;
		cout<<ans<<endl;
	}
	return 0;
}