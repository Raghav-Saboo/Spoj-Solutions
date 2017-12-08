#include <stdio.h>
#include <math.h>
long long int expo(long long int a, long long int b, long long int c) {
        long long int ans=1;
        while(b != 0) {
                if(b%2 == 1)
                        ans=(ans*a)%c;

                a=(a*a)%c;
                b /= 2;
        }
        return ans;
}
int main(void) {
	// your code goes here
	long long int n,l,s=0,i,c,k;
	c=pow(10,9)+7;
	scanf("%lld %lld",&n,&l);
	do
	{
		s=0;
		for(i=1;i<=l;i++)
		{
			k=expo(n,i,c);
			s=s+k;
			s=s%c;
		}
		printf("%lld\n",s);
		scanf("%lld %lld",&n,&l);
		if(n==0&&l==0)
		{
			break;
		}
	}
	while(1);
	return 0;
}
