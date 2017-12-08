#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli f[1000005];
map <lli,lli> mp;
void pre()
{
	lli i;
	for(i=0;i<=1000000;i++)
	{
		f[i]=(i*i+i+2)/2;
		mp[f[i]]=i;
	}
}
int main() {
	// your code goes here
	pre();
	lli t,n,l,h,m,p;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		l=0;
		h=1000000;
		while(l<=h)
		{
			m=(l+h)/2;
			if(f[m]==n)
			{
				p=f[m];
				break;
			}
			else if(f[m]>n)
			{
				p=f[m];
				h=m-1;
			}
			else
			{
				l=m+1;
			}
		}
		printf("%lld\n",mp[p]);
	}
	return 0;
}