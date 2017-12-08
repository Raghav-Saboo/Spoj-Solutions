#include <stdio.h>

int main(void) {
	// your code goes here
	long long int n,t,a,i,s[1000001],x=1000000003;
	scanf("%lld",&t);
	s[1]=1%x;
	a=0;
	for(i=1;i<=1000000;i++)
	{			
		a=(a+i*i*i)%x;
		s[i]=(a+s[i-1])%x;	
	}
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",s[n]);
	}
	return 0;
}
