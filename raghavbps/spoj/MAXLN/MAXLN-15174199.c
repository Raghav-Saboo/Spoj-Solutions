#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	long long int r;
	double s;
	int i;
	for(i=1;i<=t;i++)
	{
		scanf("%lld",&r);
		s=4*r*r+.25;
		printf("Case %d: %.2f\n",i,s);
	}
	return 0;
}
