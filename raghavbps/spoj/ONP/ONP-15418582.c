#include <stdio.h>
#include <string.h>
int main(void) 
{
	int t,l;
	char s[400],d[400],c[400];
	int i=0,k=0,m=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
	
		k=0;
		m=0;
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			{
			
				d[k++]=s[i];
			}
			else if(s[i]!=')')
			{
				c[m++]=s[i];
			}
			else
			{
				while(c[--m]!='(')
				{
					d[k++]=c[m];
				}
			}
		}
		for(i=0;i<k;i++)
		{
			
			printf("%c",d[i]);
		}
		printf("\n");
	}
	return 0;
}
