#include <stdio.h>

int main(void) {
	// your code goes here
	long long int a,b,s;
	scanf("%lld%lld",&a,&b);
	s=(b*(b+1)*(2*b+1))/6-((a-1)*(a)*(2*a-1))/6;
	printf("%lld",s);
	return 0;
}
