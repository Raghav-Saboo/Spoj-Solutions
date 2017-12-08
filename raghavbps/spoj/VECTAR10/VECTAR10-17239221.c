#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ans[1000005];
void pre()
{
	int i;
	ans[1]=1;
	ans[2]=2;
	ans[3]=2;
	ans[4]=4;
	ans[5]=2;
	for(i=6;i<=1000000;i++)
	{
		if(i%2==0)
		{
			ans[i]=(ans[i/2])*2;
		}
		else
		{
			ans[i]=(ans[i/2+1]-1)*2;
		}
	}
}
int main() {
	// your code goes here
	int n;
	pre();
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		printf("%d\n",ans[n]);
	}
	return 0;
}