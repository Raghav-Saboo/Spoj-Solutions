#include <stdio.h>

int main(void) {
	// your code 
	long long int n,t;
	scanf("%lld",&n);
	while(n!=0)
	{
		t=((n)*(n+1)*(2*n+1))/6;
		printf("%lld\n",t);
		scanf("%lld",&n);
	}

	return 0;
}