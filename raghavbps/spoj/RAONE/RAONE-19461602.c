#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli dp[10][2][85][85];
lli g;
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
lli solve(string s,lli sm,lli ind,lli sum,lli es,lli os)
{
	if(ind==s.size())
	{
		if(es-os==1)
		{
		//	cout<<es<<" "<<os<<" "<<sum<<endl;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(dp[ind][sm][es][os]!=-1)
	{
		return dp[ind][sm][es][os];
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
			if(i<s[ind]-'0'&&(ind+g)%2==0)
			{
				cnt+=solve(s,0,ind+1,sum+i,es+i,os);
			}
			else if(i<s[ind]-'0'&&(ind+g)%2!=0)
			{
				cnt+=solve(s,0,ind+1,sum+i,es,os+i);
			}
			else if((ind+g)%2==0)
			{
				cnt+=solve(s,sm,ind+1,sum+i,es+i,os);	
			}
			else
			{
				cnt+=solve(s,sm,ind+1,sum+i,es,os+i);
			}
		}
		dp[ind][sm][es][os]=cnt;
		return cnt;
	}
}
int main()
{
    lli t,a,b,x,y;
    cin>>t;
    while(t--)
    {
    	cin>>a>>b;
    	memset(dp,-1,sizeof(dp));
    	string s=tostring(a-1);
    	if(s.size()%2!=0)
    	{
    		g=1;
    	}
    	else
    	{
    		g=0;
    	}
    	x=solve(s,1,0,0,0,0);
    	memset(dp,-1,sizeof(dp));
    	//cout<<x<<endl;
    	s=tostring(b);
    	if(s.size()%2!=0)
    	{
    		g=1;
    	}
    	else
    	{
    		g=0;
    	}
    	y=solve(s,1,0,0,0,0);
    //	cout<<y<<endl;
    	cout<<y-x<<endl;
    }
} 