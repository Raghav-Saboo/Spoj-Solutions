#include <iostream>
using namespace std;
#define lli long long int
int main() {
	// your code goes here
	lli a,b,c;
	cin>>a>>b>>c;
	if(b==a)
	{
		cout<<"YES"<<endl;
	}
	else if(b<a&&c>0)
	{
		cout<<"NO"<<endl;
	}
	else if(b>a&&c<0)
	{
		cout<<"NO"<<endl;
	}
	else if((b-a)%c==0)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}