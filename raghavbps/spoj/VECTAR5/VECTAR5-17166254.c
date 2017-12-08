#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
long int m=1e9+7;
lli bexp(lli a,lli b)
{
	if(b==0)
	{
		return 1;
	}
	lli t=bexp(a,b/2);
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
	lli ans,t,n,a,b;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		a=bexp(2,n);
		b=bexp(3,n);
		ans=(((a+1)*(a-2))%m-(2*(b-a-1))%m+m)%m;
		cout<<ans<<endl;
	}
	return 0;
}