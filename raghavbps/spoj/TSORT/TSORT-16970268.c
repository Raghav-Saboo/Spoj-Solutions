#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long int a[1000005];
int main() {
	// your code goes here
	long int i,n;
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
		}
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			printf("%ld\n",a[i]);
		}
	
	return 0;
}