#include <bits/stdc++.h>
using namespace std;
void mul(long long int a[][2],long long int b[][2],long long int c[][2],long long int p)
{
	int i,j,k;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			c[i][j]=0;
			for(k=0;k<2;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
				c[i][j]%=p;
			}
		}
	}
}
void power(long long int a[][2],long long int b,long long int ans[][2],long long int p)
{
	int i,j;
	if(b==0)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
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
	long long int tmp[2][2];
	power(a,b/2,tmp,p);
	if(b%2==0)
	{
		mul(tmp,tmp,ans,p);
	}
	else
	{
		mul(tmp,tmp,ans,p);
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{	
				tmp[i][j]=ans[i][j];
			}
		}
		mul(tmp,a,ans,p);
	}
}
int main() {
	int t,i,j,k;
	long long int n,m,p;
	long long int mt[2][1],ans[2][2],fa[2][1];
	cin>>t;
	long long int a[2][2]={{1,1},{1,0}};
	fa[0][0]=2;
	fa[1][0]=1;
	while(t--)
	{
		cin>>n>>m;
		p=pow(2,m);
		if(n>=3)
		{
			power(a,n-2,ans,p);
			for(i=0;i<2;i++)
			{
				for(j=0;j<1;j++)
				{
					mt[i][j]=0;
					for(k=0;k<2;k++)
					{
						mt[i][j]+=ans[i][k]*fa[k][j];
						mt[i][j]%=p;
					}
				}
			}
		}
		else
		{
			if(n==1)
			{
				mt[0][0]=1;
			}
			else
			{
				mt[0][0]=2;
			}
		}
		cout<<mt[0][0]<<endl;
	}
	return 0;
}