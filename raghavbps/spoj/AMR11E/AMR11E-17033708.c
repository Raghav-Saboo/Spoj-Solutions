#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1000005],prf[1000005],ln[1005],k=0;
void sieve()
{
	int i,j;
	for(i=2;i*i<1000000;i++)
	{
		if(!a[i])
		{
			for(j=i*2;j<1000000;j+=i)
			{
				prf[j]++;
				a[j]=1;
			}
		}
	}
	for(i=2;i<5000;i++)
	{
		if(prf[i]>=3)
		{
			ln[++k]=i;
			//cout<<i<<" ";
		}
		if(k>=1000)
		{
			break;
		}
	}
}
int main() {
	// your code goes here
	int t,n;
	cin>>t;
	sieve();
	while(t--)
	{
		cin>>n;
		cout<<ln[n]<<endl;
	}
	return 0;
}