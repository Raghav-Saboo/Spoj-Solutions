#include <stdio.h>

int main(void) {
	// your code goes here
	long long int t,a,b,c,s;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		s=a*a-2*b;
		printf("%lld\n",s);
	}
	return 0;
}
