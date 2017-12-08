#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
vector <int> pr;
int k=0;
void sieve()
{
	int i,j;
	a[1]=1;
	for(i=2;i*i<1000000;i++)
	{
		if(!a[i])
		{
			for(j=i*i;j<1000000;j+=i)
			{
				a[j]=1;
			}
		}
	}
	for(i=2;i<1000000;i++)
	{
		if(!a[i])
		{
			//cout<<i<<" ";
			pr.push_back(i);
		}
	}
}
int compute(int an,int b,int n)
{
	int i,j,ans,c,p,q=0;
	for(i=an;i<=b;i++)
	{
		p=i;
		ans=1;
		for(j=0;(pr[j]*pr[j])<=i;j++)
		{
			c=0;
			while(p%pr[j]==0)
			{
				p/=pr[j];
				c++;
			}
			ans*=(c+1);
		}
		if(p>1)
		{
			ans*=2;
		}
		//cout<<ans<<" ";
		if(ans==n)
		{
			q++;
		}
	}
	return q;
}
int main() {
	// your code goes here
	sieve();
	int a,b,n;
	cin>>a>>b>>n;
	cout<<compute(a,b,n)<<endl;
	return 0;
}