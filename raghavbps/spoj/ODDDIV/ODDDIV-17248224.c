#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int a[100005];
map <lli,lli> ans;
vector <lli> v[2000];
lli mn=1;
void sieve()
{
	lli i,j,p,c;
	for(i=1;i<=100000;i++)
	{
		ans[i*i]=1;
	}
	for(i=2;i<=100000;i++)
	{
		if(!a[i])
		{
			for(j=i;j<=100000;j+=i)
			{
				a[j]=1;
				p=j*j;
				c=0;
				while(p%i==0)
				{
					p/=i;
					c++;
				}
				ans[j*j]*=(c+1);
			}
		}
	}
	for(i=2;i<=100000;i++)
	{
		mn=max(mn,ans[i*i]);
		v[ans[i*i]].push_back(i*i);
	}
}
int main() {
	// your code goes here
	sieve();
	lli t,a,b,k,d;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&k,&a,&b);
		if(k>mn)
		{
			d=0;
		}
		else
		{
			d=(upper_bound(v[k].begin(),v[k].end(),b)-v[k].begin())-(lower_bound(v[k].begin(),v[k].end(),a)-v[k].begin());
		}
		printf("%lld\n",d);
	}
	//cout<<mn<<" "<<ans[36]<<endl;
	return 0;
} 