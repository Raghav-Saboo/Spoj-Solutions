#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	double vo;
	long long int u,v,w,U,V,W,t,u1,v1,w1;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&w,&u,&v,&V,&U,&W);
		u1 = v*v + w*w - U*U;
		v1 = w*w + u*u - V*V;
		w1 = u*u + v*v - W*W;
		vo=sqrt(4*u*u*v*v*w*w-u*u*u1*u1-w*w*w1*w1-v*v*v1*v1+u1*v1*w1)/12.0;
		printf("%.4lf\n",vo);
		
	}
	return 0;
}
