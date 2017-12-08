#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	long long int n,k;
	scanf("%lld",&n);
	int i,flag=0;
	for(i=0;i<=50;i++)
	{
		k=pow(2,i);
		if(k==n)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("TAK\n");
	}
	else
	{
		printf("NIE\n");
	}
	return 0;
}
