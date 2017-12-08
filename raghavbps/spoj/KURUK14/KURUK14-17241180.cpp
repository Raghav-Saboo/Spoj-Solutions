#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map <int,int> mp;
int arr[1005];
int main() {
	// your code goes here
	int t,n,i,j,flag;
	cin>>t;
	while(t--)
	{
		cin>>n;
		flag=1;
		for(i=1;i<=n;i++)
		{
			cin>>arr[i];
			mp[arr[i]]++;
		}
		if(n%2!=0)
		{
			j=(n-1)/2;
			if(mp.find(j)==mp.end())
			{
				flag=0;
			}
			else if(mp[j]!=1)
			{
				flag=0;
			}
			else
			{
				mp.erase(j);
			}
		}
		for(i=1;i<=n/2-1;i++)
		{
			if(mp.find(i)!=mp.end()&&mp[i]>2)
			{
				flag=0;
			}
			if(mp.find(n-i-1)!=mp.end()&&mp[n-i-1]>2)
			{
				flag=0;
			}
			if(mp.find(i)!=mp.end()&&mp.find(i)!=mp.end()&&(mp[i]+mp[n-i-1])!=2)
			{
				flag=0;
			}
			if(mp.find(i)!=mp.end())
			{
				mp.erase(i);
			}
			if(mp.find(n-i-1)!=mp.end())
			{
				mp.erase(n-i-1);
			}	
		}
		if(mp[n-1]!=2||mp.size()!=1)
		{
			flag=0;
		}
		if(flag)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		mp.clear();
	}
	return 0;
} 