#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	double a,b,c,r;
	while(t--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		r=((a*b*c)/(a*b+b*c+c*a+2*sqrt((a*b*c)*(a+b+c))));
		printf("%lf\n",r);
		
	}
	return 0;
}
