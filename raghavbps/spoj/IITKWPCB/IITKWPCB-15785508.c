#include <stdio.h>
#include <math.h>
long long int gcd(long long int a,long long int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int main(void) {
	// your code goes here
	int t;
	long long int i,f,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		m=floor(n/2);
		for(i=m;i>=1;i--)
		{
			f=gcd(n,i);
			if(f==1)
			{
				printf("%lld\n",i);
				break;
			}
		}
	}
return 0;
}