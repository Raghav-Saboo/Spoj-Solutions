#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	double v,h,ans;
	while(1)
	{
		cin>>v>>h;
		if(v==-1&&h==-1)
		{
			break;
		}
		ans=sqrt(v*v+2*9.8*h);
		ans*=v;
		ans/=9.8;
		printf("%.6lf\n",ans);
	}
	return 0;
}