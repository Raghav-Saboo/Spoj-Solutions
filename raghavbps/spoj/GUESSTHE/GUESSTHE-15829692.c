#include <stdio.h>
#include <string.h>
long long int lcm(int a,int b,int x) 
{
 if(a%b)
 {
 	lcm(a+x,b,x);
 }
 else
 {
 	return a;
 }
} 
int main(void) {
	// your code goes here
	char s[21];
	int a[20],b[20],i,j,k,l;
	long long int lc;
	while(1)
	{
		lc=1;
		scanf("%s",s);
		l=strlen(s);
		if(strcmp(s,"*")==0)
		{
			break;
		}
		else
		{
			j=0;
			k=0;
			for(i=0;i<l;i++)
			{
				if(s[i]=='Y')
				{
					a[j++]=i+1;
				}
				else if(s[i]=='N')
				{
					b[k++]=i+1;
				}
			}
			lc=a[0];
			for(i=1;i<j;i=i+1)
			{
				if(lc<a[i])
				{
					lc=lcm(a[i],lc,a[i]);
				}
 				else 
 				{
 					lc=lcm(lc,a[i],lc);
 				}
			}
			for(i=0;i<k;i++)
			{
				if(lc%b[i]==0)
				{
					lc=-1;
					break;
				}
			}
			printf("%lld\n",lc);
		}
	}
	return 0;
}

