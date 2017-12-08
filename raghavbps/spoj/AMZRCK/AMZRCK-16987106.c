#include <iostream>
using namespace std;
#define lli long long int
lli fib[100];
void pre()
{
	lli i;
	fib[1]=2;
	fib[2]=3;
	for(i=3;i<80;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
}
int main() {
	// your code goes here
	lli t,n;
	pre();
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<fib[n]<<endl;
	}
	return 0;
}