#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	int n,a[10000],i,c=0,mean,sum=0,t,j;
	while(1)
	{
		c=0;
		sum=0;
		scanf("%d",&n);
		if(n==-1)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%n==0)
		{
			mean=sum/n;
			for(i=0;i<n;i++)
			{
				if(a[i]<mean)
				{
					c=c+mean-a[i];
				}
			}
			printf("%d\n",c);
		}
		else
		{
			printf("-1\n");
		}
	}

	return 0;
}
