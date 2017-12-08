#include <stdio.h>
#include <string.h>

int main(void)
{
	// your code goes here
	while(5)
	{
	int c,i,j;
	scanf("%d",&c);
	if(c==0)
	break;
	else
	{
		int r,l;
		int k=0;
		char str[200];
		scanf("%s",str);
		l=strlen(str);
		r=l/c;
		char a[r][c];
		for(i=0;i<r;i++)
		{
			if(i%2==0)
			{
				for(j=0;j<c;j++)
				{
					a[i][j]=str[k];
					k++;
				}
			}
			else
			{
				k+=c;
				k--;
				for(j=0;j<c;j++)
				{
					a[i][j]=str[k];
					k--;
				}
				k++;
				k+=c;
					
			}
			
		}
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%c",a[j][i]);
		}
	}
	printf("\n");
		
	}
	
	}
	
	
	
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
