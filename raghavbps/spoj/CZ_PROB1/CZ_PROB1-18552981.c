#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> pr;
#define lli long long int
lli dp1[10005],dp2[10005],dp3[10005];
int a[10005];
void pre()
{
	int i,j;
	for(i=2;i<=1e4;i++)
	{
		if(!a[i])
		{
			for(j=i*2;j<=1e4;j+=i)
			{
				a[j]=1;
			}
		}
	}
	pr.push_back(2);
	for(i=2;i<=1e4;i++)
	{
		if(!a[i]&&(i-1)%4==0)
		{
			pr.push_back(i);
		}
	}
	for(i=1;i<=1e4;i++)
	{
		dp1[i]=1;
	}
	dp2[0]=1;
	for(i=1;i<=2;i++)
	{
		for(j=i;j<=1e4;j++)
		{
			dp2[j]+=dp2[j-i];
		}
	}
	dp3[0]=1;
	for(i=1;i<=3;i++)
	{
		for(j=i;j<=1e4;j++)
		{
			dp3[j]+=dp3[j-i];
		}
	}
}
int main() {
	// your code goes here
	pre();
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k==1)
		{
			cout<<"1\n";
		}
		else if(k==2)
		{
			cout<<dp2[pr[n-1]]<<endl;
		}
		else
		{
			cout<<dp3[pr[n-1]]<<endl;
		}
	}
	return 0;
}