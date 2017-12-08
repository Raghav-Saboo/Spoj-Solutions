#include <bits/stdc++.h>
using namespace std;
long int a[50005],ma=50005,pr[50005],k;
void sieve()
{
	long int i,j;
	for(i=2;i*i<ma;i++)
	{
		if(!a[i])
		{
			for(j=i*i;j<ma;j+=i)
			{
				a[j]=1;
			}
		}
	}
	k=0;
	for(i=2;i<ma;i++)
	{
		if(!a[i])
		{
			pr[k++]=i;
		}
	}
	return;
}
int main()
{
	long int t,n,i,m=1000000007,c=0,j;
	cin>>t;
	long long int f;
	sieve();
	while(t--)
	{
		cin>>n;
		f=1;
		for(i=0;i<k;i++)
		{
			c=0;
			for(j=n/pr[i];j>0;j=j/pr[i])
			{
				c+=j;
			}
			f*=(c+1);
			f%=m;
		}
		cout<<f<<endl;
	}
	return 0;
}
	
	