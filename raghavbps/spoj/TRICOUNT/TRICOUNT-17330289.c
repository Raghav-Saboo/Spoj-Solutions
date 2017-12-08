#include <iostream>
using namespace std;
#define lli long long int
int main() {
	// your code goes here
	lli t,n,ans,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		x=(n*(n+1)*(n+2))/6;
		if(n%2==0)
		{
			ans=(n*(n+2)*(2*n-1))/24;
		}
		else
		{
			ans=((n*n-1)*(2*n+3))/24;
		}
		ans+=x;
		cout<<ans<<endl;
	}
	return 0;
}