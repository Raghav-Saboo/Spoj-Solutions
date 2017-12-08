#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x;
int rec(string s)
{
	if(s[x]=='l')
	{
		return 0;
	}
	else
	{
		int l,r;
		x++;
		l=rec(s);
		x++;
		r=rec(s);
		return 1+max(l,r);
	}
}
int main() {
	// your code goes here
	int t,l;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		x=0;
		cout<<rec(s)<<endl;
	}
	return 0;
}