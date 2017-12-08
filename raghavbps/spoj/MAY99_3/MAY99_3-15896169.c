#include <stdio.h>
long long int gcd(long long int a,long long int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	}
}
int main(void) {
	// your code goes here
	long long int t,x,y,z,g;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		g=gcd(x,y);
		if(z%g==0&&((x>=z)||(y>=z)))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
