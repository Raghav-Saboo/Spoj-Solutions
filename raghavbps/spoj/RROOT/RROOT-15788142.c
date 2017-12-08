#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	int t;
	double ar,fc;
	double s,sc;
	float p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&s);
		ar=(4*pow(s/2,1.5))/3.0;
		sc=s*s;
		fc=sc-ar;
		p=fc/sc;
		printf("%f\n",p);
	}
	return 0;
}
