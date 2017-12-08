#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <pair<long int,long int>> a;
vector <pair<long int,long int>> :: iterator it;
map <long int,long int> m;
map <long int,long int> mf;
bool compare(const pair<long int, long int>&i, const pair<long int, long int>&j)
{
	if(i.second==j.second)
	{
		return m[i.first]>m[j.first];
	}
    return i.second > j.second;
}
int main() {
	// your code goes here
	long int s[2000];
	long int n,c,i,f;
	cin>>n>>c;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(i=0;i<n;i++)
	{
		if(m[s[i]]==0)
		{
			m[s[i]]=n-i;
		}
		mf[s[i]]++;
	}
	for(i=0;i<n;i++)
	{
		if(mf.find(s[i])!=mf.end())
		{
			a.push_back(pair<long int,long int> ((s[i]),mf[s[i]]));
			mf.erase(s[i]);
		}
	}
	sort(a.begin(),a.end(),compare);  
    for(it=a.begin();it!=a.end();it++)
    {
    	for(i=1;i<=it->second;i++)
    	{
    			cout<<it->first<<" ";
    	}
    }
    return 0;
}