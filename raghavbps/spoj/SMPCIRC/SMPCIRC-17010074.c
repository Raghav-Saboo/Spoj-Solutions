#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	// your code goes here
	lli x1,y1,r1,x2,y2,r2,min,max;
	double d;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		if(r1>r2)
		{
			max=r1;
			min=r2;
		}
		else
		{
			max=r2;
			min=r1;
		}
		if(d==abs(r1-r2))
		{
			cout<<"E"<<endl;
		}
		else if((d+min)<max)
		{
			cout<<"I"<<endl;
		}
		else
		{
			cout<<"O"<<endl;
		}
	}
	return 0;
}