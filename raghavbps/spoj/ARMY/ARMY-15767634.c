
#include <stdio.h>

int main(void) {
	// your code goes here
	int t,a;
	scanf("%d",&t);
	int ng,nmg,mg,mmg,i;
	while(t--)
	{
		mg=0;
		mmg=0;
		scanf("%d%d",&ng,&nmg);
		for(i=1;i<=ng;i++)
		{
			scanf("%d",&a);
			if(mg<a)
			{
				mg=a;
			}
		}
		for(i=1;i<=nmg;i++)
		{
			scanf("%d",&a);
			if(mmg<a)
			{
				mmg=a;
			}
		}
		if(mg>=mmg)
		{
			printf("Godzilla\n");
		}
		else
		{
			printf("MechaGodzilla\n");
		}
	}
	return 0;
}
