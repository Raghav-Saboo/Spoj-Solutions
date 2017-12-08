#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli m=1e9+7;
lli dp[100005];
lli add[10]={1,2,3,2,3,4,3,3,3,2};
lli tmp[10];
void pre()
{
	dp[1]=10;
	lli i,j;
	for(i=2;i<=1e5;i++)
	{
		for(j=0;j<10;j++)
		{
			dp[i]+=add[j];
			dp[i]%=m;
		}
		tmp[0]=add[7]%m;
		tmp[1]=(add[2]+add[4])%m;
		tmp[2]=(add[1]+add[3]+add[5])%m;
		tmp[3]=(add[2]+add[6])%m;
		tmp[4]=(add[1]+add[5]+add[7])%m;
		tmp[5]=(add[2]+add[4]+add[6]+add[8])%m;
		tmp[6]=(add[3]+add[5]+add[9])%m;
		tmp[7]=(add[0]+add[4]+add[8])%m;
		tmp[8]=(add[5]+add[7]+add[9])%m;
		tmp[9]=(add[6]+add[8])%m;
		for(j=0;j<10;j++)
		{
			add[j]=tmp[j];
		}
	}
}
int main() {
	// your code goes here
	pre();
	int t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",dp[n]);
	}
	return 0;
}