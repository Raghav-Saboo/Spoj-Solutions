#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
int main() {
	// your code goes here
	long long int s,n[100000],q[100000],i,j,c=0,d=1;
	scanf("%lld",&s);
	for(i=0;i<s;i++)
	{
		scanf("%lld",&q[i]);
	}
	for(i=0;i<s;i++)
	{
		scanf("%lld",&n[i]);
	}
	long long int *p1,*p2;
	sort(q,q+s);
	sort(n,n+s);
	p1=n;
	p2=q;
	while(d<=s)
	{
		if(*p1>*p2)
		{
			c++;
			p1++;p2++;d++;
		}
		else
		{
			p1++;d++;
		}
	}
	printf("%lld\n",c);
	return 0;
}
