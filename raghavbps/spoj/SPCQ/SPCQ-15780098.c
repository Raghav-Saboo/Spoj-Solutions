#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	long long int i,n,s,r,d;
	while(t--)
	{
		scanf("%lld",&n);
		for(i=n;;i++)
		{
			r=i;
			s=0;
			while(r>0)
			{
				d=r%10;
				s=s+d;
				r=r/10;
			}
			if(i%s==0)
			{
				printf("%lld\n",i);
				break;
			}
		}
	}
	return 0;
}
