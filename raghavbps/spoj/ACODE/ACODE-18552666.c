#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli dp[5005];
int main() {
	// your code goes here
	string s;
	int i,l,x,flag;
	while(1)
	{
		memset(dp,0,sizeof(dp));
		cin>>s;
		if(s.compare("0")==0)
		{
			break;
		}
		l=s.size();
		flag=1;
		for(i=0;i<l-1;i++)
		{
			if(s[i]=='0'&&s[i+1]=='0')
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			if(s[l-1]!='0')
			{
				dp[l-1]=1;
			}
			if(l>=2&&s[l-1]!='0')
			{
				x=s[l-2]-'0';
				x*=10;
				x+=s[l-1]-'0';
				dp[l-2]=dp[l-1];
				if(x<=26)
				{
					dp[l-2]+=1;
				}	
			}
			else if(s[l-1]=='0'&&l>=2)
			{
				x=s[l-2]-'0';
				x*=10;
				x+=s[l-1]-'0';
				if(x<=26)
				{
					dp[l-2]=1;
				}
				else
				{
					flag=0;
				}
			}
			if(flag)
			{
				for(i=l-3;i>=0;i--)
				{
					if(s[i]!='0'&&s[i+1]!='0')
					{
						x=s[i]-'0';
						x*=10;
						x+=s[i+1]-'0';
						dp[i]=dp[i+1];
						if(x<=26)
						{
							dp[i]+=dp[i+2];
						}
					}
					else if(s[i]!='0')
					{
						x=s[i]-'0';
						x*=10;
						x+=s[i+1]-'0';
						if(x<=26)
						{
							dp[i]+=dp[i+2];
						}
						else
						{
							flag=0;
						}
					}
				//	cout<<i<<" "<<dp[i]<<endl;
				}
			}
		}
		if(!flag)
		{
			dp[0]=0;
		}
		cout<<dp[0]<<endl;
	}
	return 0;
}