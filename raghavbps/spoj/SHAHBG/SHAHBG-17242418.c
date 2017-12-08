#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map <int,int> m;
int main() {
	// your code goes here
	int q,x,i,c=1;
	cin>>q;
	cin>>x;
	cout<<"1"<<endl;
	m[x]++;
	cin>>i;
	if(abs(x-i)!=1)
	{
		c++;
	}
	m[i]++;
	cout<<c<<endl;
	for(i=3;i<=q;i++)
	{
		cin>>x;
		c++;
		m[x]++;
		if(m.find(x+1)!=m.end())
		{
			c--;
		}
		if(m.find(x-1)!=m.end())
		{
			c--;
		}
		cout<<c<<endl;
	}
	cout<<"Justice"<<endl;
	return 0;
} 