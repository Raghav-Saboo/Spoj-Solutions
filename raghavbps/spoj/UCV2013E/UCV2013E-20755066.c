#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli m=1e9+7;
lli x[55],y[55];
lli fac[505],ifac[505];
lli mexp(lli a,lli b,lli md)
{
	lli res=1;
	while(b>0)
	{
		if(b%2==1)
		{
			res*=a;
			res%=md;
		}
		a=(a*a)%md;
		b/=2;
	}
	return res;
}
void pre()
{
	lli i;
	fac[0]=fac[1]=1;
	ifac[0]=ifac[1]=1;
	for(i=2;i<=500;i++)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=m;
	}
	for(i=2;i<=500;i++)
	{
		ifac[i]=ifac[i-1]*mexp(i,m-2,m);
		ifac[i]%=m;
	}
}
int main()
{
	pre();
	lli n,i,ans,j;
	while(1)
	{
		cin>>n;
		if(n==0)
		{
			break;
		}
		for(i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(i=1;i<=n;i++)
		{
			cin>>y[i];
		}
		ans=1;
		lli s=0;
		for(i=1;i<=n;i++)
		{
			x[i]=abs(x[i]-y[i]);
			s+=x[i];
		}
		ans=ans*fac[s];
		ans%=m;
		for(i=1;i<=n;i++)
		{
			ans=ans*ifac[x[i]];
			ans%=m;
		}
		cout<<ans<<endl;
	}
	return 0;
}