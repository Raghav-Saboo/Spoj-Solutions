#include <stdio.h>

int main(void) {
	// your code goes here
	long int t,n,i,c;
	scanf("%ld",&t);
	while(t--)
	{
		c=0;
		scanf("%ld",&n);
		c=n-n/2;
		printf("%ld\n",c);
	}
	return 0;
}
