#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[100005],n;
bool pre(int x,int c)
{
	int i,r=1;
	int prv=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]-prv>=x)
		{
			r++;
			prv=arr[i];
		}
	}
	if(r>=c)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int binary_search(int l,int r,int c)
{
	int mid,ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(pre(mid,c))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}
int main() {
	// your code goes here
	int t,i,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		cout<<binary_search(0,arr[n-1],c)<<endl;
	}
	return 0;
}