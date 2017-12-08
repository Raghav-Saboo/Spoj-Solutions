#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
double strl(lli n)
{
	double ans=n*log(n)-n+(0.5*log(2*3.14159*n));
	return ans;
}
int main() {
	// your code goes here
	lli a,t,l,h,m,ans;double x,y;
	cin>>t;
	while(t--)
	{
		cin>>a;
		x=log(a);
		l=4;
		h=3*a;
		while(l<=h)
		{
			m=(l+h)/2;
			y=m*x;
			if(strl(m)>=y)
			{
				ans=m;
				h=m-1;
			}
			else if(strl(m)<y)
			{
				l=m+1;
			}
		}
		y=ans*x;
		while(strl(ans)<y)
		{
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}