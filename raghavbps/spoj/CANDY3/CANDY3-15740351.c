#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	long long int n,c,s,i;
	while(t--)
	{
		s=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&c);
			s=s+c;
			s=s%n;
		}
		if(s==0)
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