#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli arr[300005];
int main() {
	// your code goes here
	lli prv,n,m,i,msf,ans;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	msf=0;
	prv=1;
	ans=0;
	for(i=1;i<=n;i++)
	{
		msf+=arr[i];
		while(msf>m)
		{
			msf-=arr[prv];
			prv++;
		}
		ans=max(ans,msf);
	}
	cout<<ans;
	return 0;
} 