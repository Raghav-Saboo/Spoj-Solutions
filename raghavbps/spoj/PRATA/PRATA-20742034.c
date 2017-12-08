#include <bits/stdc++.h>
using namespace std;
int rk[55];
int ds(int mid,int l)
{
	int i,c=0;
	for(i=1;i<=l;i++)
	{
		int x=2*mid;
		x/=rk[i];
		int d=sqrt(1+4*x)-1;
		d/=2;
		c+=max(0,d);
	}
	return c;
}
int bs(int p,int l)
{
	int low,high,mid;
	int ans;
	low=1;
	high=4004000;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(ds(mid,l)>=p)
		{
			ans=mid;
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return ans;
}
int main()
{
	int t,p,l,i;
	cin>>t;
	while(t--)
	{
		cin>>p>>l;
		for(i=1;i<=l;i++)
		{
			cin>>rk[i];
		}
		cout<<bs(p,l)<<endl;
	}
	return 0;
}