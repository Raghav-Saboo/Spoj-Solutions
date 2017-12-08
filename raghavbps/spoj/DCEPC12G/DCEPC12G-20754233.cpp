#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define N 10000000
lli m=1e9+7;
lli a[N+5];
lli fac[N+5];
lli s[N+5];
vector <int> pr;
void pre()
{
	lli i,j;
	for(i=2;i*i<=1e7;i++)
	{
		if(!a[i])
		{
			pr.push_back(i);
			for(j=i*i;j<=1e7;j+=i)
			{
				a[j]=1;
			}
		}
	}
	for(i=2;i<=1e7;i++)
	{
		s[i]=s[i-1]+!a[i];
	}
	fac[0]=1;
	fac[1]=1;
	for(i=2;i<=1e7;i++)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=(m-1);
	}
}
lli mexp(lli a,lli b)
{
	if(b==0)
	{
		return 1;
	}
	lli tmp=mexp(a,b/2);
	if(b%2==0)
	{
		return (tmp*tmp)%m;
	}
	else
	{
		return (((tmp*tmp)%m)*(a%m))%m;
	}
}
int main()
{
	pre();
	lli t,n,ans,i,f,g;
	cin>>t;
	while(t--)
	{
		cin>>n;
		g=n;
		lli phi=n;
		for(i=0;i<pr.size()&&pr[i]*pr[i]<=n;i++)
		{
			if(n%pr[i]==0)
			{
				phi/=pr[i];
				phi*=(pr[i]-1);
			}
			while(n%pr[i]==0)
			{
				n/=pr[i];
			}
		}
		if(n>1)
		{
			phi/=n;
			phi*=(n-1);
		}
		if(s[g]-phi>=0)
		{
			f=s[g]-phi;
		}
		else
		{
			f=0;
		}
		ans=mexp(phi,fac[f]);
		cout<<ans<<endl;
	}
	return 0;
}