#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[205][205];
char ch[205][205];
void rec(int m,int n)
{
	int i,j,c;
	if(m%2!=0)
	{
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				if(ch[m][j]=='#')
				{
					break;
				}
				else if(ch[m][j]=='T')
				{
					dp[m][i]++;
				}
			}
		}
	}
	else
	{
		for(i=n;i>=1;i--)
		{
			for(j=i;j>=1;j--)
			{
				if(ch[m][j]=='#')
				{
					break;
				}
				else if(ch[m][j]=='T')
				{
					dp[m][i]++;
				}
			}
		}		
	}
	for(i=m-1;i>=1;i--)
	{
		if(i%2==0)
		{
			for(j=1;j<=n;j++)
			{
				if(ch[i][j]!='#')
				{
					if((j-1)>=1)
					{
						c=max(dp[i][j-1],dp[i+1][j]);
					}
					else
					{
						c=dp[i+1][j];
					}
					if(ch[i][j]=='T')
					{
						c++;
					}
					dp[i][j]=c;
				}
				else
				{
					dp[i][j]=0;
				}
			}
		}
		else
		{
			for(j=n;j>=1;j--)
			{
				if(ch[i][j]!='#')
				{
					if((j+1)<=n)
					{
						c=max(dp[i][j+1],dp[i+1][j]);
					}
					else
					{
						c=dp[i+1][j];
					}
					if(ch[i][j]=='T')
					{
						c++;
					}
					dp[i][j]=c;
				}
				else
				{
					dp[i][j]=0;
				}
			}	
		}
	}
}
int main() {
	// your code goes here
	int t,m,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				dp[i][j]=0;
				cin>>ch[i][j];
			}
		}
		rec(m,n);
		cout<<dp[1][1]<<endl;
	}
	return 0;
}