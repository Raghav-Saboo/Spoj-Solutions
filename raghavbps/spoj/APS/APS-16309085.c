#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define n 10000005
unsigned long long int v[n],f[n],a[n];
void sieve()
{
	long int i,j;
	a[0]=0;
	a[1]=0;
	for(i = 2; i*i < n; i++)
	{
		if(v[i] == 0)
		{
			for(j = i*i; j < n; j+=i)
			{
				if(!f[j])
				{
					f[j]=i;
				}
				v[j]=1;
			}
		}
	}
}
void pre()
{
	long int i,tmp;
	for(i = 2; i < n; i++)
	{
		if(v[i]==0)
		{
			f[i]=i;
		}
		a[i]=a[i-1]+f[i];
	}
}
int main() {
	// your code goes here
	int t;
	long int nn;
	cin>>t;
	sieve();
	pre();
	while(t--)
	{
		cin>>nn;
		cout<<a[nn]<<endl;
	}
	return 0;
}
