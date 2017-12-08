#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	long long int n,k,c,tmp,i,v[1000000];
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&v[i]);
	}
	sort(v,v+n);c=0;
	for(i=0;i<n;i++)
	{
		tmp=k+v[i];
		if(binary_search(v+i,v+n,tmp))
		{
			c=c+1;
		}
	}
	printf("%lld",c);
	return 0;
}