#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	int t;
	long int a,b,i,j,n,c;
	long int A[38]={2,4,9,16,25,64,289,729,1681,2401,3481,4096,5041,
 	7921,10201,15625,17161,27889,28561,29929,65536,
 	83521,85849,146689,262144,279841,458329,491401,
 	531441,552049,579121,597529,683929,703921,707281,
 	734449,829921,1190281};
	scanf("%d",&t);
	while(t--)
	{
		c=0;
		i=0;
		scanf("%ld%ld",&a,&b);
		while(A[i]<a)
		{
			i++;
		}
		while(A[i]<=b)
		{
			i++;
			c++;
		}
		printf("%ld\n",c);
	}
	return 0;
}
