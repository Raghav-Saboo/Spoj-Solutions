#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	long long int a,b,c,ar,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		ar=(c*c)/(a*b);
		ar/=2;
		if(ar<0)
		{
			ar*=-1;
		}
		printf("%lld\n",ar);
	}
	return 0;
}
