#include <iostream>
using namespace std;
#define lli long long int 
int main() {
	// your code goes here
	lli n,i,h,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		h=(((i)*(i+1)*(2*i+1))+3*(i*(i+1)))/12;
		k=(((i+1)*(i+2)*(2*i+3))+3*((i+1)*(i+2)))/12;
		if(h<=n&&k>n)
		{
			break;
		}
	}
	cout<<i<<endl;
	return 0;
}