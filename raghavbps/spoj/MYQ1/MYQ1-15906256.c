#include <stdio.h>

int main(void) {
	// your code goes here
	long long int t,n,i,p,c;char ch,d;
	scanf("%lld",&t);
	while(t--)
	{
		d='L';
		scanf("%lld",&n);
		c=n/5;
		if(n>5*c+1)
		{
			c++;
		}
		i=5*c+1;
		p=i-n;
		if(p==0||p==4)
		{
			ch='W';
		}
		else if(p==3&&c%2==0)
		{
			ch='M';
		}
		else if(p==1&&c%2!=0)
		{
			ch='M';
		}
		else
		{
			ch='A';
		}
		if((n>=i-2&&c%2!=0)||(n<=i-2&&c%2==0))
		{
			d='R';
		}
		if(n==1)
		{
			printf("poor conductor\n");
		}
		else
		{
			printf("%lld %c %c\n",c,ch,d);
		}
	}
	return 0;
}
