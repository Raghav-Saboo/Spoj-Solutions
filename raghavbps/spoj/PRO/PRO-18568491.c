#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
multiset <int> se;
int main() {
	// your code goes here
	int n,x,i,j,c;
	multiset <int> :: iterator it;
	multiset <int> :: reverse_iterator rit;
	lli ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		for(j=1;j<=x;j++)
		{
			cin>>c;
			se.insert(c);
		}
		it=se.begin();
		rit=se.rbegin();
		ans+=*rit-*it;
		se.erase(se.find(*it));
		se.erase(se.find(*rit));
	}
	cout<<ans<<endl;
	return 0;
}