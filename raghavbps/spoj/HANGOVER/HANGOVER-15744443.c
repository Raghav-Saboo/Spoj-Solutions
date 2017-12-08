#include <stdio.h>
float sum(int n)
{
	float s=0.0;
	float i;
	for(i=2;i<=n;i++)
	{
		s=s+1/i;
	}
	return s;
}
int main(void) {
	// your code goes here
	int i;
	float c,f;
	while(1)
	{
		scanf("%f",&c);
		if(c==0.00)
		{
			break;
		}
		for(i=1;;i++)
		{
			f=sum(i+1);
			if(f>=c)
			{
				printf("%d card(s)\n",i);
				break;
			}
		}
	}
	return 0;
}
