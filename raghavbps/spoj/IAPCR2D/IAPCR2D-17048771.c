#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
lli a[10005],pr[10005],k,df[120];
void sieve()
{
	lli i,j;
	for(i=2;i*i<10005;i++)
	{
		if(!a[i])
		{
			for(j=i*i;j<10005;j+=i)
			{
				a[j]=1;
			}
		}
	}
	k=0;
	for(i=2;i<120;i++)
	{
		if(!a[i])
		{
			pr[k++]=i;
		}
	}
}
void pre()
{
	sieve();
	lli i,j,c,f,p;
	for(p=1;p<=110;p++)
	{
		f=1;
		for(i=0;i<k;i++)
		{
			c=0;
			for(j=p/pr[i];j>0;j/=pr[i])
			{
				c+=j;
			}
			f*=(c+1);
		}
		df[p]=f;
		//cout<<f<<endl;
	}
}
int main() {
	// your code goes here
	pre();
	lli t,n,i,flag;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		flag=0;
		for(i=1;i<=110;i++)
		{
			if(df[i]==n)
			{
				printf("%lld\n",i);
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			printf("nai\n");
		}
	}
	return 0;
}