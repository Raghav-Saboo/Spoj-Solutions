#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[106];
lli pr[105],cg=0;
void pre()
{
	lli i,j;
	for(i=2;i<=100;i++)
	{
		if(!a[i])
		{
			pr[cg++]=i;
			for(j=i*2;j<=100;j+=i)
			{
				a[j]=1;
			}
		}
	}
}
int main()
{
	pre();
	lli n,k,i,j,ans=0,c,r,p,q;
	cin>>n>>k;
	for(i=0;i<k;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<(1<<k);i++)
	{
		c=0;
		r=1;
		lli cnt[105]={0};
		for(j=0;j<k;j++)
		{
			if(i&(1<<j))
			{
				c++;
				p=a[j];
				for(q=0;q<cg;q++)
				{
					r=0;
					while(p%pr[q]==0)
					{
						p/=pr[q];
						r++;
					}
					if(cnt[q]<r)
					{
						cnt[q]=r;
					}
				}
			}
		}
		r=1;
		for(p=0;p<cg;p++)
		{
			if(r>n)
			{
				break;
			}
			for(q=0;q<cnt[p];q++)
			{
				r*=pr[p];
			}
		}

		if(c%2!=0)
		{
			ans+=n/r;
		}
		else
		{
			ans-=n/r;
		}
	}
	cout<<n-ans;
	return 0;
}