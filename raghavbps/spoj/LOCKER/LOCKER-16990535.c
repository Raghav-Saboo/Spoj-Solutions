#include <iostream>
using namespace std;
#define lli long long int
long int m=1000000007;
long long int mexp(lli a,lli b)
{
	if(b==0)
	{
		return 1;
	}
	long long int t=mexp(a,b/2);
	if(b%2==0)
	{
		return (t%m*t%m)%m;
	}
	else
	{
		return ((t%m*t%m)%m*a%m)%m;
	}
}
int main() {
	// your code goes here
	lli t,n,a,b;lli ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
		{
			ans=1;
		}
		else if(n%3==0)
		{
			ans=mexp(3,n/3)%m;
		}
		else if(n%3==1)
		{
			ans=(mexp(3,(n-4)/3)%m*4)%m;
		}
		else
		{
			ans=(mexp(3,(n-2)/3)%m*2)%m;
		}
		cout<<ans<<endl;
	}
	return 0;
}