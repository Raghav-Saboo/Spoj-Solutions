#include <stdio.h>

 

int main(void) {

	// your code goes here

	int t;

	scanf("%d",&t);

	long long int i,j,n,c=0;

	for(i=1;i<=t;i++)

	{

		scanf("%lld",&n);

		for(j=5;n/j>=1;j=j*5)

		{

			c=c+n/j;
		}

	printf("%lld\n",c);

		c=0;

	}
	return 0;

}

