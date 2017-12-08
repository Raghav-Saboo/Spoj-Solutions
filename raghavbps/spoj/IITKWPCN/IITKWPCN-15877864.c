#include <stdio.h>

int main(void) {
	// your code goes here
	long long int w,b,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&w,&b);
		if(b%2==0)
		{
			printf("0.000000\n");
		}
		else
		{
			printf("1.000000\n");
		}
	}
	return 0;
}

