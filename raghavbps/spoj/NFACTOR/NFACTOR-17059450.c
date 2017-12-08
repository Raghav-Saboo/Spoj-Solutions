#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)
vector <int> v[11];
int a[1000005],gd;
void sieve()
{
	int i,j;
	for(i=2;i<=1000000;i++)
	{
		if(!a[i])
		{
			for(j=i*2;j<=1000000;j+=i)
			{
				a[j]++;
			}
		}
	}
	for(i=2;i<=1000000;i++)
	{
		if(!a[i])
		{
			a[i]=1;
		}
	}
	gd=0;
	v[0].push_back(1);
	for(i=2;i<=1000000;i++)
	{
		gd=max(gd,a[i]);
		v[a[i]].push_back(i);
	}
}
int main() {
	// your code goes here
	sieve();
	int t,a,b,n,ans;
	sc(t);
	//printf("%d\n",gd);
	while(t--)
	{
		sc(a);
		sc(b);
		sc(n);
		if(n>gd)
		{
			printf("0\n");
		}
		else
		{
			ans=upper_bound(v[n].begin(),v[n].end(),b)-v[n].begin();
			ans-=lower_bound(v[n].begin(),v[n].end(),a)-v[n].begin();
			printf("%d\n",ans);
		}
	}
	return 0;
}