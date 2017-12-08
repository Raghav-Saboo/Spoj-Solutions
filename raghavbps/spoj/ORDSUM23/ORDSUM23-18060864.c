#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli m=1e9+7;
lli dp[1000005];
void pre()
{
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	dp[4]=1;
	lli i;
	for(i=5;i<=1e6;i++)
	{
		dp[i]=dp[i-2]+dp[i-3];
		dp[i]%=m;
	}
}
int main() {
	// your code goes here
	pre();
	lli t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}