#include <stdio.h>
#define pi 3.1415926
int main(void) {
	// your code goes here
	int l;
	float ar;
	while(1)
	{
		scanf("%d",&l);
		if(l==0)
		{
			break;
		}
		ar=(l*l)/(2*pi);
		printf("%.2f\n",ar);
	}
	return 0;
}
