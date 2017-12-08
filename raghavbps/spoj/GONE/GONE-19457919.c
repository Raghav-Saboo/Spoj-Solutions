#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli dp[10][2][85];
lli a[105];
void sieve()
{
	a[0]=1;
	a[1]=1;
	lli i,j;
	for(i=2;i<=100;i++)
	{
		if(!a[i])
		{
			for(j=i*i;j<=100;j+=i)
			{
				a[j]=1;
			}
		}
	}
}
string tostring(lli n)
{
	string s="";
	while(n>0)
	{
		s+=(n%10+'0');
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
lli solve(string s,lli sm,lli ind,lli sum)
{
	if(ind==s.size())
	{
		if(!a[sum])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(dp[ind][sm][sum]!=-1)
	{
		return dp[ind][sm][sum];
	}
	else
	{
		lli limit;
		if(sm==1)
		{
			limit=s[ind]-'0';
		}
		else
		{
			limit=9;
		}
		lli i,cnt=0;
		for(i=0;i<=limit;i++)
		{
			if(i<s[ind]-'0')
			{
				cnt+=solve(s,0,ind+1,sum+i);
			}
			else
			{
				cnt+=solve(s,sm,ind+1,sum+i);
			}
		}
		dp[ind][sm][sum]=cnt;
		return cnt;
	}
}
int main()
{
	sieve();
    lli t,a,b,x,y;
    cin>>t;
    while(t--)
    {
    	cin>>a>>b;
    	memset(dp,-1,sizeof(dp));
    	x=solve(tostring(a-1),1,0,0);
    	memset(dp,-1,sizeof(dp));
    	y=solve(tostring(b),1,0,0);
    	cout<<y-x<<endl;
    }
}