#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	long long int n,a,i,b[1000000],c,j;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		if(a%2==0)
		{
			c=0;
			while(a>0)
			{
				b[c++]=a%2;
				a=a/2;
			}
			for(j=0;j<c;j++)
			{
				a=a+b[j]*pow(2,c-1-j);
			}
			printf("%lld\n",a);
		}
		else
		{
		printf("%lld\n",a);
		}
	}
	return 0;
}
