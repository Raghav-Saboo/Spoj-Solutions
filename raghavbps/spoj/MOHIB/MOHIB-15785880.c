#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	int x,avg,n,max,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&avg);
		n=avg-x;
		sum=avg*(n+1)-x;
		max=sum-((n)*(n-1))/2;
		printf("%d\n",max);
	}
	return 0;
}
