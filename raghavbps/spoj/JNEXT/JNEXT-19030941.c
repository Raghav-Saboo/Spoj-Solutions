#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int main() {
	// your code goes here
	int t,n,i,mn,mx,f;
	cin>>t;
	while(t--)
	{
		cin>>n;mn=10;mx=0;
		for(i=1;i<=n;i++)
		{
			cin>>arr[i];
			mn=min(mn,arr[i]);
			mx=max(mx,arr[i]);
		}
		f=0;
		for(i=n-1;i>=1;i--)
		{
			if(arr[i]<arr[i+1])
			{
				f=1;
				break;
			}
		}
		if(!f)
		{
			cout<<"-1\n";
		}
		else
		{
			int j,mn=INT_MAX,p;
			for(j=i+1;j<=n;j++)
			{
				if(arr[j]>arr[i]&&mn>arr[j])
				{
					mn=arr[j];
					p=j;
				}
			}
			int tmp=arr[p];
			arr[p]=arr[i];
			arr[i]=tmp;
			for(j=1;j<=i;j++)
			{
				cout<<arr[j];
			}
			int k,r[10]={0};
			for(j=i+1;j<=n;j++)
			{
				r[arr[j]]++;
			}
			for(j=0;j<=9;j++)
			{
				for(k=1;k<=r[j];k++)
				{
					cout<<j;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}