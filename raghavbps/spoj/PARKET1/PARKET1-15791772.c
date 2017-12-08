#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	long int r,b,l,w,a,bq,c,d,x1,x2;
	scanf("%ld%ld",&r,&b);
	a=2;
	bq=-1*(4+r);
	c=2*(b+r);
	d=sqrt(bq*bq-4*a*c);
	x1=(-bq+d)/(2*a);
	x2=(-bq-d)/(2*a);
	if(x1>x2)
	{
		l=x1;
	}
	else
	{
		l=x2;
	}
	w=(r+4-2*l)/2;
	printf("%ld %ld",l,w);
	return 0;
}
