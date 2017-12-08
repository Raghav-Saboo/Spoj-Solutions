#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli arr[100005];
lli s[100005];
int main() {
	// your code goes here
	lli fp,ans,r,l,msf,t,n,mx,i,prv;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&mx);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		s[1]=arr[1];
		for(i=2;i<=n;i++)
		{
			s[i]=s[i-1]+arr[i];
		}
		msf=0;
		ans=0;
		prv=1;
		l=0;
		for(i=1;i<=n;i++)
		{
			msf+=arr[i];
			l++;
			while(msf>mx)
			{
				msf-=arr[prv];
				prv++;
				l--;
			}
			if(ans<l)
			{
				ans=l;
			}
		}
		l=ans;
		msf=0;fp=0;
		for(i=1;i<=l;i++)
		{
			msf+=arr[i];
		}
		fp=msf;
		for(i=2;i<=n-l+1;i++)
		{
			msf-=arr[i-1];
			msf+=arr[i+l-1];
			fp=min(fp,msf);
		}
		printf("%lld %lld\n",fp,ans);
	}
	return 0;
} 