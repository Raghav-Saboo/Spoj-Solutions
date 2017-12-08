#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long int n,k,j,l;
	int i;
	long long int ans=1,f=1;
	while(scanf("%ld %ld",&n,&k)!=EOF)
	{
		ans=1;
		for(j=1;j<=n;j++)
		{
			ans*=j;
		}
		while(k--)
		{
			cin>>l;
			f=1;
			for(j=1;j<=l;j++)
			{
				f*=j;
			}
			ans/=f;
		}
		cout<<ans<<endl;
	}
	return 0;
}