#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{	
	lli t,n,i,c=0;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		c=0;
		i=n;
		while(n>0)
		{
			if(n&1)
			{
				c++;
			}
			n/=2;
		}
		n=i;
		lli ans=pow(2,c);
		if(n>0)
		{
			printf("%lld %lld\n",(n+1)-ans,ans);
		}
		else
		{
			printf("0 1\n");
		}
	}
	return 0;
}