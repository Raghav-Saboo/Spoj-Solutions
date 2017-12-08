#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	long long int t,n,m,sn,sm,p,a,b,i,j;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		p=(m-n)%4;
		if(p==1)
		{
			printf("3\n");
		}
		else if(p==2)
		{
			printf("9\n");
		}
		else if(p==3)
		{
			printf("7\n");
		}
		else
		{
			printf("1\n");
		}
	}
	return 0;
}
