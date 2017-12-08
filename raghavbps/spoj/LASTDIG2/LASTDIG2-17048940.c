#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int m=10;
int mod(string a,int m)
{
	int ans=0,l,i;
	l=a.size();
	for(i=0;i<l;i++)
	{
		ans*=10;
		ans+=a[i]-'0';
		ans%=m;
	}
	return ans;
}
int mexp(string a,lli b)
{
	if(b==0)
	{
		return 1;
	}
	int t=mexp(a,b/2);
	if(b%2==0)
	{
		return (t*t)%10;
	}
	else
	{
		return (((t%10*t%10)%10)*mod(a,10))%10;
	}
}
int main() {
	// your code goes here
	int t;
	lli b;
	string a;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<mexp(a,b)<<endl;
	}
	return 0;
}