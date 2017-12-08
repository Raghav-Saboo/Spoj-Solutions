#include <stdio.h>

int main(void) {
	// your code here
	int t;
	scanf("%d",&t);
	long long int n,i;
	while(t--)
	{
		scanf("%lld",&n);
		i=192+(n-1)*250;
		printf("%lld\n",i);
	}

	return 0;
}