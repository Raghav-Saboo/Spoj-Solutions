#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
vector <lli> v;
lli a[1000005];
void sieve()
{
	lli i,j;
	for(i=2;i<=1e6;i++)
	{
		if(!a[i])
		{
			for(j=i*i;j<=1e6;j+=i)
			{
				a[j]=1;
			}
		}
	}
	for(i=2;i<=1e6;i++)
	{
		if(!a[i])
		{
			v.push_back(i);
		}
	}
}
int tsq(lli n)
{
	lli i,c,j,r;
	for(i=0;i<v.size()&&v[i]*v[i]<=n;i++)
	{
		if(n%v[i]==0)
		{
			c=0;
			while(n%v[i]==0)
			{
				n/=v[i];
				c++;
			}
			if((v[i]-3)%4==0&&c%2!=0)
			{
				return 0;
			}
		}
	}
	if(n>1&&(n-3)%4==0)
	{
		return 0;
	}
	return 1;
}
int main() {
	// your code goes here
	sieve();
	lli c,n;
	cin>>c;
	while(c--)
	{
		cin>>n;
		if(tsq(n))
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	return 0;
}