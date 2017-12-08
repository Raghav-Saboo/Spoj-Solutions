#include <stdio.h>

int main(void) {
	// your code goes here
	int t,flag=0,p;
	long int n,i,j;
	scanf("%d",&t);
	for(p=1;p<=t;p++)
	{
		flag=0;
		scanf("%ld",&n);
		i=n/3;
		for(j=i*3;j>=3;j=j-3)
		{
			if(((n-j)!=0)&&((n-j)%5==0))
			{
				flag=1;
				printf("Case %d: %ld\n",p,j);
				break;
			}
		}
		if(flag==0)
		{
			printf("Case %d: -1\n",p);
		}
	}
	return 0;
}
