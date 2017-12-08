#include <stdio.h>
int main(void)
{
    int isPrime[10000];
    long int i,j,c,n;
    scanf("%ld",&n);
    for( i = 0; i < 10000;++i) 
    {
        isPrime[i] = 1;
    }
    isPrime[0] = 0;
    isPrime[1] = 0;
    for( i = 2; i * i < 10000; ++i) 
    {
        if(isPrime[i] == 1) 
        {
             for( j = i * i; j <10000 ;j += i)
             {
                 isPrime[j] = 0;
             }
        }
    }
    long int max=0;
    for(i=2;i<n;i++)
    {
    	if(isPrime[i]==1)
    	{
    		max=i;
    	}
    }
    
    for(i=2;i<10000;i++)
    {
    	c=0;
    	if(isPrime[i]==1)
    	{
    		for(j=i;n/j>=1;j*=i)
    		{
    			c=c+n/j;
    		}
    		if(c!=0&&max!=i)
    		{
    			printf("%ld^%ld * ",i,c);
    		}
    		else if(c!=0&&max==i)
    		{
    			printf("%ld^%ld",i,c);
    		}
    	}
    
    }
		
	// your code goes here
	return 0;
}
