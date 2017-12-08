#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	long long int t,n,v,p,i,j,c,d,a,r,e;
	int sa[1000000],sb[1000000];
	scanf("%lld",&t);
	while(t--)
	{
		c=0;a=2;v=0;
		d=0;r=2;p=0;
		scanf("%lld",&n);
		for(i=2;i<=n;i*=2)
		{
			c++;
		}
		if((a*pow(r,c))==(n+1))
		{
			c++;
		}
		j=a*pow(r,c-1);
		for(i=j-1;i<=n;i++)
		{
			d++;
		}
		e=d-1;
		while(e>0)
		{
			sa[p++]=e%2;
			e=e/2;
		}
		for(i=p;i<c;i++)
		{
			sa[i]=0;
		}
		for(i=c-1;i>=0;i--)
		{
			if(sa[i]==0)
			{
				sb[v++]=5;
			}
			else
			{
				sb[v++]=6;
			}
		}
		for(i=0;i<v;i++)
		{
			printf("%d",sb[i]);
		}
		printf("\n");
	}
	return 0;
}
