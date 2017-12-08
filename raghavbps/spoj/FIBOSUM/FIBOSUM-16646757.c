#include <iostream>
using namespace std;
long long int mod=1000000007;
long long int a[3][3]={{1,1,1},{1,0,0},{0,0,1}};
long long int b[3][1]={{1},{0},{1}};
long long int an[3][1],c[3][3],am[3][1];
void mul(long long int a[][3],long long int b[][3],long long int c[][3])
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
			for(k=0;k<3;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
				c[i][j]%=mod;
			}
		}
	}
}
void power(long long int a[][3],long long int b,long long int ans[][3])
{
	int i,j;
	if(b==0)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(i==j)
				{
					ans[i][j]=1;
				}
				else
				{
					ans[i][j]=0;
				}
			}
		}
		return;
	}
	long long int tmp[3][3];
	power(a,b/2,tmp);
	if(b%2==0)
	{
		mul(tmp,tmp,ans);
	}
	else
	{
		mul(tmp,tmp,ans);
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				tmp[i][j]=ans[i][j];
			}
		}
		mul(a,tmp,ans);
	}
}
int main() {
	// your code goes here
	int t,i,j,k;
	cin>>t;
	long long int n,m;
	while(t--)
	{
		cin>>n>>m;
		power(a,n-1,c);
		for(i=0;i<3;i++)
		{
			for(j=0;j<1;j++)
			{
				an[i][j]=0;
				for(k=0;k<3;k++)
				{
					an[i][j]+=c[i][k]*b[k][j];
					an[i][j]%=mod;
				}
			}
		}
		power(a,m-1,c);
		for(i=0;i<3;i++)
		{
			for(j=0;j<1;j++)
			{
				am[i][j]=0;
				for(k=0;k<3;k++)
				{
					am[i][j]+=c[i][k]*b[k][j];
					am[i][j]%=mod;
				}
			}
		}
		if(n==0)
		{
			an[1][0]=0;
		}
		if(m==0)
		{
			am[0][0]=0;
		}
		cout<<(am[0][0]%mod-an[1][0]%mod+mod)%mod<<endl;
	}
	return 0;
}