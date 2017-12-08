#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int a[1005];
int main() {
	// your code goes here
	int w=0,j,t,n,k,i,c,ans,p;
	cin>>t;
	while(t--)
	{
		w++;
		ans=0;
		cin>>n>>k;
		c=0;j=0;
		if(k%2==0)
		{
			while(k%2==0)
			{
				k/=2;
				c++;
			}
			a[j++]=2;
			a[j++]=c;
		}
		for(i=3;i*i<=k;i+=2)
		{
			if(k%i==0)
			{
				c=0;
				while(k%i==0)
				{
					k/=i;
					c++;
				}
				a[j++]=i;
				a[j++]=c;
			}
		}
		if(k>1)
		{
			a[j++]=k;
			a[j++]=1;
		}
		ans=0;
		for(i=0;i<j;i+=2)
		{
			c=0;
			for(p=n/a[i];p>=1;p/=a[i])
			{
				c+=p;
			}
			if(c<a[i+1]||c==0)
			{
				ans=0;
				break;
			}
			else
			{
				if(!ans)
				{
					ans=c/a[i+1];
				}
				else
				{
					ans=min(ans,c/a[i+1]);
				}
			}
		}
		cout<<"Case "<<w<<": "<<ans<<endl;
	}
	return 0;
}