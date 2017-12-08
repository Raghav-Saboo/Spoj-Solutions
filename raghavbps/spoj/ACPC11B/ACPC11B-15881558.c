#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	int t,i,j,na,nb;
	long long int a[1000],b[1000],min;
	scanf("%d",&t);
	while(t--)
	{
		min=1000000;
		scanf("%d",&na);
		for(i=0;i<na;i++)
		{
			scanf("%lld",&a[i]);
		}
		scanf("%d",&nb);
		for(i=0;i<nb;i++)
		{
			scanf("%lld",&b[i]);
		}
		for(i=0;i<na;i++)
		{
			for(j=0;j<nb;j++)
			{
				if(min>abs(a[i]-b[j]))
				{
					min=abs(a[i]-b[j]);
				}
			}
		}
		printf("%lld\n",min);
	}
	return 0;
}
