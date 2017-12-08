#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long int a[5]={3,5,17,257,65537};
int main() {
	// your code goes here
	long int t,n,f,c,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		while(n%2==0)
		{
			n/=2;
		}
		for(i=0;i<5;i++)
		{
			if(n%a[i]==0)
			{
				n/=a[i];
			}
		}
		if(n==1)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}