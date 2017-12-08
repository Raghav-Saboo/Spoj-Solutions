#include <stdio.h>

int main(void) {
	// your code here
	int a;
	while(5)
	{
		scanf("%d",&a);
		if(a==42)
		break;
		printf("%d\n",a);
	}

	return 0;
}