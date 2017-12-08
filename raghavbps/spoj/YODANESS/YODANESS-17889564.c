#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
vector <string> v;
int bit[30005],a[30005];
void update(int ind,int n)
{
	while(ind<=n)
	{
		bit[ind]++;
		ind+=(ind)&(-ind);
	}
}
int query(int ind)
{
	int s=0;
	while(ind>0)
	{
		s+=bit[ind];
		ind-=(ind)&(-ind);
	}
	return s;
}
int main() {
	// your code goes here
	int t,n,i,ans;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>s;
			v.push_back(s);
		}
		for(i=1;i<=n;i++)
		{
			cin>>s;
			mp[s]=i;
		}
		for(i=0;i<v.size();i++)
		{
			a[i+1]=mp[v[i]];
		}
		for(i=1;i<=n;i++)
		{
			bit[i]=0;
		}
		ans=0;
		for(i=n;i>=1;i--)
		{
			ans+=query(a[i]-1);
			update(a[i],n);
		}
		cout<<ans<<endl;
		v.clear();
		mp.clear();
	}
	return 0;
}