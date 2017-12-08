#include<stdio.h>
int main()
{
	long long int t, n, m, p;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld",&n);
		m = ((30 % 11)*(n % 11));
		p = m%11;
		if(p)
		{
			m = 11-p;
		}
		else
		{
			m=0;
		}	
		printf("%lld\n",m);
	}
}