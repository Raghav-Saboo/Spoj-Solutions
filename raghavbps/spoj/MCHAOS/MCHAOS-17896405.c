#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli b=27;
int bit[1000005];
vector <lli> v;
vector <lli> av;
struct st
{
	lli hs;
	lli rhs;
};
struct st arr[1000005];
void update(int ind,int n)
{
	while(ind<=n)
	{
		bit[ind]+=1;
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
lli gethash(string s)
{
	lli h=0,i,l;
	l=s.size();
	for(i=0;i<l;i++)
	{
		h*=b;
		h+=(s[i]-'a'+1);
	}
	for(i=l;i<10;i++)
	{
		h*=b;
	}
	return h;
}
int cmp(struct st a,struct st b)
{
	return a.hs<b.hs;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	lli q,n,i,ans=0;
	string s;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		arr[i].hs=gethash(s);
		reverse(s.begin(),s.end());
		arr[i].rhs=gethash(s);
		v.push_back(arr[i].rhs);
	}
	sort(arr+1,arr+1+n,cmp);
	sort(v.begin(),v.end());
	for(i=1;i<=n;i++)
	{
		q=lower_bound(v.begin(),v.end(),arr[i].rhs)-v.begin()+1;
		av.push_back(q);
		//cout<<q<<" ";
	}
	for(i=av.size()-1;i>=0;i--)
	{
		ans+=query(av[i]-1);
		update(av[i],n);
	}
	cout<<ans<<endl;
	return 0;
}