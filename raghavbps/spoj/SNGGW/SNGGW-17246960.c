#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,t,ans,i,s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%2!=0)
		{
			s=0;
			for(i=1;i<=n/2;i++)
			{
				s+=i;
			}
			s+=(3*n+1)/2;
			ans=n*n+1-s;
		}
		else
		{
			s=0;
			for(i=1;i<=n/2+1;i++)
			{
				s+=i;
			}
			ans=n*n-s;				
		}
		cout<<"DWON"<<" "<<ans<<endl;
	}
	return 0;
}