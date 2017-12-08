#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	// your code goes here
	lli t,n,x,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		x=sqrt(n);
		if(x*x==n)
		{
			ans=2*x-1;
		}
		else if((x*(x+1))==n)
		{
			ans=2*x;
		}
		else if((x*(x+1))<n)
		{
			ans=2*(x+1)-1;
		}
		else if((x*(x+1))>n)
		{
			ans=2*x;
		}
		printf("%lld\n",ans);
	}
	return 0;
}