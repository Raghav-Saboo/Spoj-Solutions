#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[105];
int main() {
	// your code goes here
	int t,n,i,k,j,s;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		sort(arr+1,arr+1+n);
		for(i=1;i<=n;i++)
		{
			if(k==0)
			{
				break;
			}
			if(arr[i]<0)
			{
				arr[i]=-1*arr[i];
				k--;
			}
		}
		sort(arr+1,arr+1+n);
		if(k%2!=0)
		{
			arr[1]=-1*arr[1];
		}
		s=0;
		for(i=1;i<=n;i++)
		{
			s+=arr[i];
		}
		cout<<s<<endl;
	}
	return 0;
}