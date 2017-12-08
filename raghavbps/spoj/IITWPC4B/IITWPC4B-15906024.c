#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	long long int t,n,c,result;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		 if(n%2==0)
		 {
  			c=n*n;
  			if(c%48>24)
  			{
				 result= c/48  + 1;
  			}
  			else
  			{
   				result= c/48;
  			}
		 }
		 else
		 {
  			c=(n+3)*(n+3);
  			if(c%48>24)
  			{
   				result= c/48 + 1;
  			}
  			else
  			{
   				result= c/48;
  			}
		 }
		printf("%lld\n",result);
	}
	return 0;
}
