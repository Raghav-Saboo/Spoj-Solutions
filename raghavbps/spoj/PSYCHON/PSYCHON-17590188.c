#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli int
lli a[10005];
vector <lli> v;
void seive()
{
	lli i,j,p,c;
	a[0]=1;
	a[1]=1;
	for(i=2;i*i<=1e4;i++)
	{
		if(!a[i])
		{
		//	s[i]--;
			for(j=i*i;j<=1e4;j+=i)
			{
				a[j]=1;
				//v.push_back(i);
			}
		}
	}
	for(i=2;i<=1e4;i++)
	{
		if(!a[i])
		{
			v.push_back(i);
		}
	}
}
int main() {
	// your code goes here
	lli t,n,ans,c,i;
	seive();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n!=0&&n!=1)
		{
			ans=0;
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
					if(c%2==0)
					{
						ans++;
					}
					else
					{
						ans--;
					}
				}
			}
			if(n>1)
			{
				ans--;
			}
		}
		else
		{
			ans=0;
		}
		if(ans>0)
		{
			printf("Psycho Number\n");
		}
		else
		{
			printf("Ordinary Number\n");
		}
	}
	return 0;
}