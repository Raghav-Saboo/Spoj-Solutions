#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli phi[100005];
lli ans[100005];
void pre()
{
	lli i,j;
	for(i=1;i<=1e5;i++)
	{
		phi[i]=i;
	}
	for(i=1;i<=1e5;i++)
	{
		for(j=i*2;j<=1e5;j+=i)
		{
			phi[j]-=phi[i];
		}
	}
	ans[1]=0;
	for(i=2;i<=1e5;i++)
	{
		ans[i]=ans[i-1]+(i-phi[i]);
	}
}
int main()
{
	pre();
	lli n,t,cn=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cn++;
		cout<<"Case "<<cn<<": "<<ans[n]<<endl;
	}
}