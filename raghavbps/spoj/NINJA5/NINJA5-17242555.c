#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main() {
	// your code goes here
	int t,n,k,i,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			a[i]++;
		}
		for(i=1;i<=k;i++)
		{
			scanf("%d",&x);
			a[x]++;
			if(x-1>=1&&x-1<=n)
			{
				a[x-1]=0;
			}
			if(x+1>=1&&x+1<=n)
			{
				a[x+1]=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				if(i-1>=1&&i-1<=n)
				{
					a[i-1]=0;
				}
				if(i+1>=1&&i+1<=n)
				{
					a[i+1]=0;
				}			
			}
		}
		x=0;
		for(i=1;i<=n;i++)
		{
			if(a[i])
			{
				x++;
			}
			a[i]=0;
		}
		printf("%d\n",x);
	}
	return 0;
}