#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    long int an,bn,i,t,l,pa,pb;
    scanf("%ld",&t);
    int flag;
    char s[100],a[100],b[100];
    while(t--)
    {
    	flag=0;
    	an=0;
    	bn=0;
		scanf("%s + %s = %s",a,b,s);
     	l=strlen(a);
    	for(i=0;i<l;i++)
     	{
     		if(a[i]=='m')
     		{
     			flag=1;
     			break;
     		}
     	}
     	if(flag!=1)
     	{
     		l=strlen(b);
    		for(i=0;i<l;i++)
     		{
     			if(b[i]=='m')
     			{
     				flag=2;
     				break;
     			}
     		}     		
     	}
     if(flag==1)
     {
     	pa=strlen(b);
        for(i=pa-1;i>=0;i--)
        {
            an+=(b[i]-'0')*pow(10,pa-1-i);
        }
        pb=strlen(s);
        for(i=pb-1;i>=0;i--)
        {
            bn+=(s[i]-'0')*pow(10,pb-1-i);
        }
        printf("%ld + %ld = %ld\n",bn-an,an,bn);
    }
    else if(flag==2)
     {
       pa=strlen(a);
   for(i=pa-1;i>=0;i--)
   {
    an+=(a[i]-'0')*pow(10,pa-1-i);
   }
   pb=strlen(s);
   for(i=pb-1;i>=0;i--)
   {
    bn+=(s[i]-'0')*pow(10,pb-1-i);
   }
   printf("%ld + %ld = %ld\n",an,bn-an,bn);
     }
     else
     {
      pa=strlen(a);
      for(i=pa-1;i>=0;i--)
      {
       an+=(a[i]-'0')*pow(10,pa-1-i);
      }
      pb=strlen(b);
      for(i=pb-1;i>=0;i--)
      {
       bn+=(b[i]-'0')*pow(10,pb-1-i);
      }
      printf("%ld + %ld = %ld\n",an,bn,an+bn);
     }
    }
    return 0;
}
