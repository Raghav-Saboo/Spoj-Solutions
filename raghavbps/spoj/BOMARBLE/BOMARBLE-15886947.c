#include <stdio.h>
int main(void) {
	// your code goes here
	int n,a1,a2,i,c;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		if(n==1)
		{
			printf("5\n");
			continue;
		}
		if(n==2)
		{
			printf("12\n");
			continue;
		}
		a1=10;
		a2=12;
		for(i=3;i<=n;i++)
		{
			c=a1+a2;
			a1+=3;
			a2=c;
		}
		printf("%d\n",c);
	}
	return 0;
}
