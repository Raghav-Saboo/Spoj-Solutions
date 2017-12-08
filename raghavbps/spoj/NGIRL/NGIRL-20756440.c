#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[1000005];
int main()
{
	lli i,j;
	vector <lli> v;
	for(i=2;i<=1e6;i++)
	{
		if(!a[i])
		{
			v.push_back(i*i);
			for(j=i*i;j<=1e6;j+=i)
			{
				a[j]=1;
			}
		}
	}
	lli n,k,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		lli ans=upper_bound(v.begin(),v.end(),n)-v.begin();
		if(k<=n)
		{
			cout<<ans<<" "<<ans-(upper_bound(v.begin(),v.end(),k)-v.begin())<<endl;
		}
		else
		{
			cout<<ans<<" 0"<<endl;
		}
	}
	return 0;
}