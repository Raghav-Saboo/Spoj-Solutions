#include <stdio.h>

int main(void) {
	// your code goes here
	long long int a,b,s=0,d=2,n;
	scanf("%lld%lld",&a,&b);
	if(a%2==0)
	{
		a++;
	}
	if(b%2==0)
	{
		b--;
	}
	n=(b-a)/d+1;
	s=n*(b+a)/2;
	printf("%lld\n",s);
	return 0;
}
