#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int m=10;
int mexp(int a,lli b)
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
		return (t*t*a)%10;
	}
}
int main() {
	// your code goes here
	int t;
	lli b;
	int a;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<mexp(a,b)<<endl;
	}
	return 0;
}