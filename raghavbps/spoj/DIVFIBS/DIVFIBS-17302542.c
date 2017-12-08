#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli f[100005];
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	lli t,l,r,m,ans,i;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>l>>r>>m;
		f[1]=1%m;
		f[2]=1%m;
		for(i=3;i<=r;i++)
		{
			f[i]=f[i-1]+f[i-2];
			f[i]%=m;
		}
		for(i=l;i<=r;i++)
		{
		//	cout<<i<<" "<<f[i]<<endl;
			if(f[i]%m==0)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}