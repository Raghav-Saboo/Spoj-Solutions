#include <bits/stdc++.h>
using namespace std;
#define N 1000001
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
		for(j=i*2;j<=N;j+=i)
		{
			a[j]=a[j]+i*phi[j/i];
		}
	}
	ans[1]=a[1];
	for(i=2;i<=N;i++)
	{
		ans[i]=ans[i-1]+a[i];
	}
}
int main()
{
	pre();
	lli n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
		{
			break;
		}
		printf("%lld\n",ans[n]);
	}
	return 0;
}