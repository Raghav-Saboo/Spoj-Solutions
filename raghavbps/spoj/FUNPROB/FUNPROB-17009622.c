#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int n,m;
	double ans;
	while(1)
	{
		cin>>n>>m;
		if(n==0&&m==0)
		{
			break;
		}
		if(n>m)
		{
			printf("0.000000\n");
		}
		else if(n<m)
		{
			ans=(float(m))/(m+n);
			printf("%.6lf\n",ans);
		}
		else
		{
			ans=1.0/(m+1);
			printf("%.6lf\n",ans);
		}
	}
	return 0;
}