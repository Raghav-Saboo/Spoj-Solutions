#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	long long int a,n,d,x,y,z,i,an;
	while(t--)
	{
		scanf("%lld %lld %lld",&x,&y,&z);
		n=(2*z)/(x+y);
		d=((y-x)*(y+x))/(2*z-5*(x+y));
		a=x-2*d;
		printf("%lld\n",n);
		for(i=n;i>=1;i--)
		{
			an=a+(n-i)*d;
			printf("%lld ",an);
		}
		printf("\n");
	}
	return 0;
}
