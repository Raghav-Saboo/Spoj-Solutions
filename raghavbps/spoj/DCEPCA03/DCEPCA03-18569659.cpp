#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli phi[10005],s[10005];
void pre()
{
	lli i,j;
	for(i=1;i<=1e4;i++)
	{
		phi[i]=i;
	}
	for(i=2;i<=1e4;i++)
	{
		if(phi[i]==i)
		{
			for(j=i;j<=1e4;j+=i)
			{
				phi[j]/=i;
				phi[j]*=(i-1);
			}
		}
	}
	s[1]=phi[1];
	for(i=2;i<=1e4;i++)
	{
		s[i]=s[i-1]+phi[i];
	}
}
int main() {
	// your code goes here
	pre();
	lli t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",s[n]*s[n]);
	}
	return 0;
}