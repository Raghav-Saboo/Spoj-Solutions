#include <stdio.h>
int gcd( int x, int y)
{
	if(y==0)
	{
		return x;
	}
	gcd(y,x%y);
}
int main(void) {
	// your code goes here
	int t,gc;
	scanf("%d",&t);
	long int x,y;
	while(t--)
	{
		scanf("%ld %ld",&x,&y);
		gc=gcd(x,y);
		printf("%ld %ld\n",y/gc,x/gc);
	}
	return 0;
}
