#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
lli a[200005],fs[200005],rs[200005];
int main() {
	// your code goes here
	lli i,n,q,l,r,x;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&q);
	fs[1]=a[0];
	for(i=2;i<=n;i++)
	{
		fs[i]=fs[i-1]+a[i-1];
	}
	rs[1]=a[n-1];
	rs[n]=fs[n];
	rs[0]=0;
	for(i=2;i<=n-1;i++)
	{
		rs[i]=fs[n]-fs[n-i];
	}
	while(q--)
	{
		scanf("%lld",&x);
		if(x==1)
		{
			scanf("%lld%lld",&l,&r);
			if(r==n)
			{
				printf("%lld\n",rs[n-l+1]);
			}
			else if(l==r)
			{
				printf("%lld\n",rs[n-l+1]-rs[n-l]);
			}
			else
			{
				printf("%lld\n",rs[n-l+1]-rs[n-r]);
			}
		}
		else
		{
			scanf("%lld",&l);
			rs[n+1]=rs[n]+l;
			n++;
		}
	}
	return 0;
}