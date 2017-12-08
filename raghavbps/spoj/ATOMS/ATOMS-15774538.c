#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	int t;
	long long int n,k,m;long long int b;
	float ti,g;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&k,&m);
		ti=log(m/n)/log(k);
		b=(int)ti;
		if(m<=n)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n",b);
		}
	}
	return 0;
}