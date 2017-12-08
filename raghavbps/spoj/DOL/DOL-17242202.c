#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	// your code goes here
//	sieve();
	lli t,n,i,ans,c,p=1;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==2||n==1)
		{
			ans=1;
		}
		else
		{
			ans=1;
			while(n%2==0)
			{
				n/=2;
			}
			ans=n;
		}
		printf("Case %lld: %lld\n",p,ans);
		p++;
	}
	return 0;
}