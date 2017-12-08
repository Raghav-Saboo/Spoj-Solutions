#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	long long int n,m,c,tmp,i,v[1000000],t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&v[i]);
		}
		sort(v,v+n);c=0;
		for(i=0;i<n;i++)
		{
			tmp=m-v[i];
			if(tmp==v[i])
			{
				c=c-1;
			}
			if(binary_search(v+i,v+n,tmp))
			{
				c=c+1;
			}
		}
		printf("%lld\n",c);
	}
	return 0;
}