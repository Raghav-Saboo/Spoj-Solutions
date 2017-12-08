#include <stdio.h>

int main(void) {
	// your code goes here
	long long int n;
	scanf("%lld",&n);
	if(n%10==0)
	{
		printf("2");
	}
	else
	{
		printf("1\n%lld",n%10);
	}
	return 0;
}
