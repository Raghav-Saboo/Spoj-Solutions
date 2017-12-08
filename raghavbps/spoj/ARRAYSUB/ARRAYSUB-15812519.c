#include <stdio.h>

int main(void) {
	// your code goes here
	long int n,k,a[1000000],i,j,max;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		max=a[0];
	}
	scanf("%lld",&k);
	for(i=0;i<n-k+1;i++)
	{
		for(j=i;j<k+i;j++)
		{
			if(a[j]>max)
			{
				max=a[j];
			}
		}
		printf("%lld ",max);
		max=0;
	}
	return 0;
}
