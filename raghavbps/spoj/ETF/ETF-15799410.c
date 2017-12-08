#include <stdio.h>
long int etf(long int n)
{
	float res=n;
	long int p;
	for(p=2;p*p<=n;p++)
	{
		if(n%p==0)
		{
			while(n%p==0)
			{
				n=n/p;
			}
			res*=(1.0-(1.0/(float)p));
		}
	}
	if (n > 1)
	{
        res *= (1.0 - (1.0 / (float) n));
	}
	return (long int)res;
}
int main(void) {
	// your code goes here
	int t;
	long int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		printf("%ld\n",etf(n));
	}
	
	return 0;
}
