#include <stdio.h>
#include <math.h>
long int gcd(long int a,long int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int main(void) {
	// your code goes here
	long int t,a,b,i,n,p,c;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&a,&b);
		c=0;
		p=1;
		n=gcd(a,b);
		while (n%2 == 0)
    	{
        	n = n/2;
        	c++;
    	}
    	p=p*(c+1);
 
    
    for ( i = 3; i <= sqrt(n); i = i+2)
    {
    	c=0;
        while (n%i == 0)
        {
            n = n/i;
            c++;
        }
        p*=(c+1);
    }
    if (n > 2)
        p=p*2;
    printf("%ld\n",p);
	}
	return 0;
}
