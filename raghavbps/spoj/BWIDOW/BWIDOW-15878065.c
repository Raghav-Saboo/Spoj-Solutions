#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	int n,i,j,p;
	long long int max,min,r[1000],rb[1000];
	scanf("%d",&t);
	while(t--)
	{
		max=1;
		min=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&r[i],&rb[i]);
			if(max<r[i])
			{
				max=r[i];
				p=i+1;
			}
		}
		for(i=0;i<n;i++)
		{
			if(max<rb[i]&&p!=i+1)
			{
				min=-1;
				break;
			}
		}
		if(min==-1)
		{
			printf("-1\n");	
		}
		else
		{
			printf("%d\n",p);
		}
	}
	return 0;
}
