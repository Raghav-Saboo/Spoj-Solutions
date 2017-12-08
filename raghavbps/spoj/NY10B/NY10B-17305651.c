#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	// your code goes here
	lli z,w,t,p,b,x,y,c,d,ans;
	cin>>t;
	while(t--)
	{
		cin>>p>>b>>x>>y;
		ans=0;
		c=x;
		d=y;
		z=1;
		while(c>0&&d>0)
		{
			w=(c%b+d%b)%b;
			c/=b;
			d/=b;
			ans+=w*z;
			z*=b;
		}
		while(c>0)
		{
			w=c%b;
			c/=b;
			ans+=w*z;
			z*=b;
		}
		while(d>0)
		{
			w=d%b;
			d/=b;
			ans+=w*z;
			z*=b;
		}	
		cout<<p<<" "<<ans<<endl;
	}
	return 0;
}