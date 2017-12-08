#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli int
lli a[1000005],s[1000005],pr[1000005];
lli chk(lli x)
{
	while(x>0)
	{
		if(x%10==0)
		{
			return 1;
		}
		x/=10;
	}
	return 0;
}
lli trn(lli x)
{
	lli d,c=0;
	d=x;
	while(d>0)
	{
		c++;
		d/=10;
	}
	while(x>0)
	{
		if(a[x])
		{
			return 0;
		}
		d=pow(10,c-1);
		c--;
		x=x%d;
	}
	return 1;
}
void pre()
{
	long long int i,j;
	a[1]=1;pr[1]=1;
	a[0]=1;
	for(i=2;i<=1e6;i++)
	{
		if(!a[i])
		{
			if(chk(i))
			{
				pr[i]=1;
			}
			for(j=i*i;j<=1e6;j+=i)
			{
				pr[j]=1;
				a[j]=1;
			}
		}
	}
	for(i=2;i<=1e6;i++)
	{
		if(!a[i]&&!pr[i]&&!trn(i))
		{
			pr[i]=1;
		}
	}
	s[0]=0;
	s[1]=0;
	s[2]=1;
	for(i=3;i<=1e6;i++)
	{
		s[i]+=s[i-1]+!pr[i];
	}
}
int main() {
	// your code goes here
	pre();
	lli t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",s[n]);
	}
	return 0;
}