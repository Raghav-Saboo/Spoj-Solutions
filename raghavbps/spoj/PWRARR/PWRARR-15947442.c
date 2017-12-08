#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
	// your code goes here
	long long int c=0,t,n,a[500000],s,i,j;
	scanf("%lld",&t);
	while(t--)
	{
		c=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		s=(n*(n+1))/2;
		for(i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
			{
				c++;
				s+=c;
			}
			else
			{
				c=0;
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}