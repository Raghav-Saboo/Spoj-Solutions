#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
long int m = 1000000009;
lli b = 100000007,invb;
lli h[100005],rh[100005];
lli mexp(lli a,lli b)
{
	if(b==0)
	{
		return 1;
	}
	lli t=mexp(a,b/2);
	if(b%2==0)
	{
		return (t%m*t%m)%m;
	}
	else
	{
		return ((t%m*t%m)%m*a%m)%m;
	}
}
void init(string s)
{
	lli i,l=s.size();invb=mexp(b,m-2);
	h[0]=s[0]-'a';
	for(i=1;i<l;i++)
	{
		h[i]=((s[i]-'a')*mexp(b,i))%m+h[i-1]%m;
		h[i]%=m;
	}
	rh[l-1]=s[l-1]-'a';
	for(i=l-2;i>=0;i--)
	{
		rh[i]=((s[i]-'a')*mexp(b,l-1-i))%m+rh[i+1]%m;
		rh[i]%=m;
	}
}
lli getfh(lli i,lli j)
{
	lli jh,ih,ans;
	jh=h[j];
	ih=(i>0)?h[i-1]:0;
	ans=(jh-ih+m)*mexp(invb,i);
	ans%=m;
	return ans;
}
lli getrh(lli i,lli j,lli l)
{
	lli ih,jh,ans;
	ih=rh[i];
	jh=(j<l-1)?rh[j+1]:0;
	ans=(ih-jh+m)*mexp(invb,l-1-j);
	ans%=m;
	return ans;
}
int main()
{
	string s;
	lli i,k,l,ans=0;
	cin>>k>>s;
	l=s.size();
	init(s);
	for(i=0;i+k<=l;i++)
	{
		if(getfh(i,i+k-1)==getrh(i,i+k-1,l))
		{
			ans++;
		}
	}
	cout<<ans<<endl;
}