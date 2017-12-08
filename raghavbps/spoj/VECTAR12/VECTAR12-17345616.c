#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
long int m=1e9+7;
lli a[7005][7005];
void pre()
{
	int i,j;
	a[0][0]=1;
	a[1][0]=1;
	a[1][1]=1;
	for(i=2;i<7000;i++)
	{
		for(j=0;j<=i;j++)
		{
			if((i-1)>=0&&(i-1)<7000)
			{
				a[i][j]+=a[i-1][j];
				a[i][j]%=m;
			}
			if((i-1)>=0&&(i-1)<7000&&(j-1)>=0&&(j-1)<7000)
			{
				a[i][j]+=a[i-1][j-1];
				a[i][j]%=m;
			}
			if((i-1)>=0&&(i-1)<7000&&(j+1)>=0&&(j+1)<7000)
			{
				a[i][j]+=a[i-1][j+1];
				a[i][j]%=m;
			}			
		}
	}
}
int main() {
	// your code goes here
	pre();
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(k>n)
		{
			printf("0\n");
		}
		else if(k==n)
		{
			printf("1\n");
		}
		else
		{
			printf("%lld\n",a[n][k]);
		}
	}
	return 0;
} 