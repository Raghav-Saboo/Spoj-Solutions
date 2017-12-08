#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long int a,b,i,c,d;
	long long int f;
	cin>>a>>b;
	f=1;
	for(i=1;i<=10000000;i++)
	{
		f*=i;
		f%=a;
		if(f==0)
		{
			break;
		}
	}
	c=i;
	f=1;
	for(i=1;i<=10000000;i++)
	{
		f*=i;
		f%=b;
		if(f==0)
		{
			break;
		}
	}	
	d=i;
	if(c>d)
	{
		f=0;
	}
	else
	{
		f=d-c;
	}
	cout<<f<<endl;
	return 0;
}