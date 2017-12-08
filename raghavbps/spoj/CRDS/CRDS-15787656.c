#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	long long int n,d=2,s=0,i,p=1000007;
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		d=2;
		scanf("%lld",&n);
		s=(n*(3*n+1))/2;
		s=s%p;
		printf("%lld\n",s);
	}
	return 0;
}
