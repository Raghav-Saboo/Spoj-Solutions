#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define lli long long int
lli phi[N+5];
lli	a[N+5];
lli ans[N+5];
void pre()
{
	lli i,j;
	for(i=1;i<=N;i++)
	{
		phi[i]=i;
	}
	for(i=1;i<=N;i++)
	{
		for(j=i*2;j<=N;j+=i)
		{
			phi[j]-=phi[i];
		}
	}
	for(i=1;i<=N;i++)
	{
		for(j=i;j<=N;j+=i)
		{
			a[j]=a[j]+i*phi[i];
		}
	}
	ans[1]=1;
	for(i=2;i<=N;i++)
	{
		ans[i]=(i+(i*a[i]))/2;
	}
}
int main()
{
	pre();
	lli n,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",ans[n]);
	}
	return 0;
}