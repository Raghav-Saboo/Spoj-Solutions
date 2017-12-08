#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long int k,n,i,ans=0,c=0,x,y;
	cin>>n>>k;
	if(k<n)
	{
		ans+=(n-k)*k;
	}
	c=k-(k/2+1);
	ans+=((c)*(c+1))/2;
	c=0;i=1;
	while(i<=k/2)
	{
		x=k/i;
		y=k%i;
		c=y/x;
		if(c+1>n-i+1)
		{	
			c=n-i;
		}
		ans+=(2*y-c*x)*(c+1)/2;
		i+=c+1;
	}
	cout<<ans<<endl;
	return 0;
}