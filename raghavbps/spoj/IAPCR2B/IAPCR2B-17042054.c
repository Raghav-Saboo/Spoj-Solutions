#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int l,i,c,t,p=1;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		l=s.size();
		c=0;
		//cout<<l<<" "<<s<<endl;
		for(i=0;i<=l-4;i++)
		{
			if(s[i]=='I'&&s[i+1]=='C'&&s[i+2]=='P'&&s[i+3]=='C')
			{
				c++;
			}
		}
		cout<<"Case "<<p<<": "<<c<<endl;
		p++;
	}
	return 0;
}