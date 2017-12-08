#include <stdio.h>

int main(void) {
	// your code goes here
	long long int a[10000],s=0,d=1;
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		d=1;s=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=n-1;i>0;i--)
		{
			s+=(n-d)*a[i];
			d++;
		}
		d=1;
		for(i=0;i<n-1;i++)
		{
			s-=(n-d)*a[i];
			d++;
		}
		printf("%lld\n",s);
	}
	return 0;
}
