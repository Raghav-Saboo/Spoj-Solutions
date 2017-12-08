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
	long long int fs,ss,n,k,i,j,gc;
	while(1)
	{
		scanf("%lld%lld",&n,&k);
		if(n==-1&&k==-1)
		{
			break;
		}
		ss=(n*(n-1))/2;fs=0;
		if(k%2==0)
		{
			fs=(k*(k-2))/4;
		}
		else
		{
			fs=((k-1)*(k-1))/4;
		}
		if(fs==0)
		{
			printf("0\n");
		}
		else if(fs==ss)
		{
			printf("1\n");
		}
		else
		{
			gc=gcd(fs,ss);
			printf("%lld/%lld\n",fs/gc,ss/gc);
		}
	}
	return 0;
}
