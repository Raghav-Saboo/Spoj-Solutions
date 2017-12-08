#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli mexp(lli a,lli b)
{
	if(b==0)
	{
		return 1;
	}
	lli t=mexp(a,b/2);
	if(b%2==0)
	{
		return t*t;
	}
	else
	{
		return t*t*a;
	}
}
lli sum(lli n)
{
	if(n<10)
	{
		return (n*(n+1))/2;
	}
	lli a[20];
	lli i;
	a[0]=0;
	a[1]=45;
	lli d=log10(n);
	for(i=2;i<=d;i++)
	{
		a[i]=a[i-1]*10+45*mexp(10,i-1);
	}
	lli p=mexp(10,d);
	lli msd=n/p;
	return a[d]*msd+((msd*(msd-1))/2)*p+msd*(n%p+1)+sum(n%p);
}
int main() {
	// your code goes here
	lli a,b;
	while(1)
	{
		cin>>a>>b;
		if(a==-1&&b==-1)
		{
			break;
		}
		cout<<sum(b)-sum(a-1)<<endl;
	}
	return 0;
}