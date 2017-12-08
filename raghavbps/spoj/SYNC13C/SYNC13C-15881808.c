#include <stdio.h>

int main(void) {
	// your code goes here
	int t,c1,c2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&c1,&c2);
		if(c1%2==0||c2%2==0)
		{
			printf("Suresh\n");
		}
		else
		{
			printf("Ramesh\n");
		}
	}
	return 0;
}