#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int a[1000005],pr[1000005],nd[1000005],ans[1000005];
void sieve()
{
	int i,j,c,x;
	for(i=1;i<=1e6;i++)
	{
		nd[i]=1;
	}
	for(i=2;i<=1e6;i++)
	{
		if(!a[i])
		{
			pr[i]=1;
			nd[i]=2;
			ans[i]=1;
			for(j=i*2;j<=1e6;j+=i)
			{
				pr[j]++;
				a[j]=1;
				x=j;
				c=0;
				while(x%i==0)
				{
					x/=i;
					c++;
				}
				if(c!=1)
				{
					ans[j]=1;
				}
				nd[j]*=(c+1);
			}
		}
	}
	for(i=2;i<=1e6;i++)
	{
		if(pr[nd[i]]==2&&!ans[nd[i]])
		{
			v.push_back(i);
		}
	}
	for(i=8;i<v.size();i+=9)
	{
		printf("%d\n",v[i]);
	}
}
int main() {
	// your code goes here
	sieve();
	return 0;
}