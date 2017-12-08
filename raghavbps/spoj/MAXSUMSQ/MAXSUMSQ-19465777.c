#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[100005];
int main() {
	// your code goes here
	lli sum,t,n,i,mx,mnct,mn,mxcnt;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		mx=-1e12;
		mn=0;
		mnct=1;
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=a[i];
			if(sum-mn>mx)
			{
				mx=sum-mn;
				mxcnt=mnct;
			}
			else if(sum-mn==mx)
			{
				mxcnt+=mnct;
			}
			if(sum<mn)
			{
				mn=sum;
				mnct=1;
			}
			else if(sum==mn)
			{
				mnct++;
			}
		}
		printf("%lld %lld\n",mx,mxcnt);
	}
	return 0;
}