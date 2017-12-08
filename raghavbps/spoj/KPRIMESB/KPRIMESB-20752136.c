#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[15];
lli pr[1000005];
lli s[1000005];
void pre()
{
	lli i,j;
	for(i=2;i<=1e6;i++)
	{
		if(!pr[i])
		{
			for(j=i*2;j<=1e6;j+=i)
			{
				pr[j]=1;
			}
		}
	}
	s[1]=0;
	s[0]=0;
	for(i=2;i<=1e6;i++)
	{
		s[i]=s[i-1]+!pr[i];
	}
}
int main()
{
	pre();
	lli t,n,k,i,j,ans,cn=0,p,q,rn;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		rn=0;
		for(i=0;i<k;i++)
		{
			cin>>a[i];
			if(a[i]<=n)
			{
				rn++;
			}
		}
		ans=0;
		for(p=1;p<(1<<k);p++)
		{
			lli c=0;
			j=1;
			for(q=0;q<k;q++)
			{
				if(p&(1<<q))
				{
					c++;
					j*=a[q];
					//cout<<a[q]<<" ";
				}
			}
			if(c%2!=0)
			{
				//cout<<n/j<<endl;
				ans=ans+n/j;
			}
			else
			{
				//cout<<-1*n/j<<endl;
				ans=ans-n/j;
			}
		}
		cn++;
		ans=n-ans-s[n]+rn-1;
		if(n<=1)
		{
			ans=0;
		}
		cout<<"Case "<<cn<<": "<<ans<<endl;
	}
	return 0;
}