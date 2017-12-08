#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	double ans=0.5;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1||n==2)
		{
			printf("%.8lf\n",ans);
		}
		else
		{
			ans=(float(n))/(n+1);
			printf("%.8lf\n",ans);
		}
	}
	return 0;
}