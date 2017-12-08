#include <stdio.h>

int main(void) 
{
	int t,i,j,l;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		char a[200];
		scanf("%s",a);
		l=strlen(a);
		for(j=0;j<l/2;j=j+2)
		{
			printf("%c",a[j]);
		
		}
		printf("\n");
	
	}
	return 0;
}