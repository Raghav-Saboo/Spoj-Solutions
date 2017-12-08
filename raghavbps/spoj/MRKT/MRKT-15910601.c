#include <stdio.h>
#include <string.h>
int main(void) {
	// your code goes here
	char a[1000][101];int t,d,i,l,c,n,f,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
		}
		l=strlen(a[0]);c=0;
		for(i=0;i<l;i++)
		{
			f=0;
			for(j=0;j<n-1;j++)
			{
				if(a[j][i]==a[j+1][i])
				{
					f++;
				}
				else
				{
					f=-1;
					break;
				}
			}
			if(f==-1)
			{
				break;
			}
			else
			{
				c++;
			}
		}
		for(i=0;i<c;i++)
		{
			printf("%c",a[0][i]);
		}
		printf("\n");
	}
	return 0;
}
