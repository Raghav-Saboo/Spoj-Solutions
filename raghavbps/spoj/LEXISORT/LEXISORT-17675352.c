#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <string> s;
vector <string> :: iterator it;
int main() {
	// your code goes here
	int k,n;
	string w;
	cin>>k;
	while(k--)
	{
		cin>>n;
		while(n--)
		{
			cin>>w;
			s.push_back(w);
		}
		sort(s.begin(),s.end());
		for(it=s.begin();it!=s.end();it++)
		{
			cout<<*it<<endl;
		}
		s.clear();
	}
	return 0;
}