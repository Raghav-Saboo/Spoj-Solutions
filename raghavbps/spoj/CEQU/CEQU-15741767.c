#include <stdio.h>
#include <math.h>
long int gcd(long int a,long int b)
{
	if(b==0)
	{
		return a;
	}
	gcd(b,a%b);
}
int main()
{
	long int t,a,b,c,i=1,g;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld %ld",&a,&b,&c);
		g=gcd(abs(a),abs(b));
		if(c%g==0)
		{
			printf("Case %ld: Yes\n",i);
		}
		else
		{
			printf("Case %ld: No\n",i);
		}
		i++;
	}
	return 0;
}


