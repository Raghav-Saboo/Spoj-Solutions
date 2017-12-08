#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	// your code goes here
	lli a,b,t,sqa,sqb,x1,ans,i,x2;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		sqa=sqrt(a);
		sqb=sqrt(b);
		i=sqa;
		x1=(i+1)*(i+1)-i*i;
		x2=(i+1)*(i+1)-i*i;
		for(i=sqa+1;i<sqb;i++)
		{
			x1=x1&((i+1)*(i+1)-i*i);
			x2=x2^((i+1)*(i+1)-i*i);
		}
		ans=x1&x2;
		cout<<ans<<endl;
	}
	return 0;
}