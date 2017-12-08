#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10000005],s[10000005];
void sieve()
{
	int i,j;
	for(i=2;i*i<=1e7;i++)
	{
		if(!a[i])
		{
			for(j=i*i;j<=1e7;j+=i)
			{
				a[j]=1;
			}
		}
	}
	s[1]=0;
	s[2]=1;
	s[3]=2;
	for(i=4;i<=1e7;i++)
	{
		s[i]=s[i-1]+!a[i];
	}
}
int main() {
	// your code goes here
	sieve();
	int t,n,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",s[n]-s[n/2]);
	}
	return 0;
}