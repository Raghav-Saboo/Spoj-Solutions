#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define sc(x) scanf("%lld",&x)
lli arr[1005][1005];
int main() {
	// your code goes here
	lli i,j,n,ansb=0,ansa=0,p,q,t=1;
	while(1)
	{
		ansb=0;
		ansa=0;
		sc(n);
		if(!n)
		{
			break;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				sc(arr[i][j]);
				ansb+=arr[i][j];
			}
		}
		for(i=1;i<=n;i++)
		{
			p=0;
			for(j=1;j<=n;j++)
			{
				p+=arr[i][j];			
			}
			q=0;
			for(j=1;j<=n;j++)
			{
				q+=arr[j][i];
			}
			if((p-q)>=0)
			{
				ansa+=(p-q);
			}
		}
		printf("%lld. %lld %lld\n",t,ansb,ansa);
		t++;
	}
	return 0;
}