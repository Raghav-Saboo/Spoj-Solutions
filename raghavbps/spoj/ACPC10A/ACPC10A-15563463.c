#include <stdio.h>

int main(void) {
	// your code here
	int a1,a2,a3,a4;
	while(1)
	{
		scanf("%d %d %d",&a1,&a2,&a3);
		if(a1==0&&a2==0&&a3==0)
		{
			break;
		}
		if((a2-a1)==(a3-a2))
		{
			a4=a3+(a2-a1);
			printf("AP %d\n",a4);
		}
		else if((a2/a1)==(a3/a2))
		{
			a4=a3*(a2/a1);
			printf("GP %d\n",a4);
		}
	}

	return 0;
}