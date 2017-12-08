#include <stdio.h>
#include <string.h>
int main(void) {
	// your code goes here
	int t,c,l,i;
	char s[10];
	scanf("%d",&t);
	while(t--)
	{
		c=0;
		scanf("%s",s);
		l=strlen(s);
		for(i=0;i<l/2;i++)
		{
			if(s[i]==s[l-1-i])
			{
				c++;
			}
		}
		if(c==l/2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
