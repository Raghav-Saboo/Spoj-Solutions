#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int mod(string a,long long int m)
{
	long long int ans=0,l,i;
	l=a.size();
	for(i=0;i<l;i++)
	{
		ans*=10;
		ans+=a[i]-'0';
		ans%=m;
	}
	return ans;
}
long long int st(string a)
{
	long long int i,l;
	l=a.size();
	long long int ans=0;
	for(i=l-1;i>=0;i--)
	{
		ans+=(a[i]-'0')*pow(10,l-1-i);
	}
	return ans;
}
long long int gcd(string a,long long int b)
{
	if(b==0)
	{
		return st(a);
	}
	else
	{
		return gcd(to_string(b),mod(a,b));
	}
}
int main() {
	// your code goes here
	long long int b;
	string a;
	long long int t;
	cin>>t;
	while(t--)
	{
		cin>>b>>a;
		if(b!=0)
		{
			cout<<gcd(a,b)<<endl;
		}
		else
		{
			cout<<a<<endl;
		}
	}
	return 0;
}