#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int arr[1000005];
int main() {
	// your code goes here
	long long int t,n,i,ans;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>s>>arr[i];
		}
		sort(arr,arr+n);
		ans=0;
		for(i=0;i<n;i++)
		{
			ans+=abs(i+1-arr[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}