#include <bits/stdc++.h>
using namespace std;
map <char,int> m;
int main() {
	// your code goes here
	int n,i;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ch;
		m[ch]++;
	}
	if(m['O']>=1&&m['L']>=1&&m['P']>=1&&m['I']>=1&&m['U']>=1&&m['H']>=1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}