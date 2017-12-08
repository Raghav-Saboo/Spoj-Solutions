#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int arr[1000005];
int main() {
	// your code goes here
	long long int t,x,y,i,c,n,d;
	double w;
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>w;
		n=x;
		while(n!=1)
		{
			d=n/2;
			if(d%2!=0&&n%2!=0)
			{
				w*=4.0;
			}
			else if(d%2!=0&&n%2==0)
			{
				w*=2.0;
			}
			else if(d%2==0&&n%2!=0)
			{
				w*=2.0;
			}
			else
			{
				w*=2.0;
			}
			n/=2;
		}
		c=0;
		n=y;
		while(n!=1)
		{
			arr[c++]=n;
			n/=2;
		}
		arr[c++]=n;
		for(i=c-1;i>=1;i--)
		{
			if(arr[i]%2!=0&&arr[i-1]%2!=0)
			{
				w/=4.0;
			}
			else if(arr[i]%2!=0&&arr[i-1]%2==0)
			{
				w/=2.0;
			}
			else if(arr[i]%2==0&&arr[i-1]%2!=0)
			{
				w/=2.0;
			}
			else
			{
				w/=2.0;
			}
		}
		printf("%.6lf\n",w);
	}
	return 0;
}