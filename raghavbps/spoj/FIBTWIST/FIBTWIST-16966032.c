#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void mul(long long int a[][4],long long int b[][4],long long int c[][4],long int m)
{
	int i,j,k;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			c[i][j]=0;
			for(k=0;k<4;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
				c[i][j]%=m;
			}
		}
	}
}
void power(long long int a[][4],long long int b,long long int ans[][4],long int m)
{
	int i,j;
	if(b==0)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
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
	long long int tmp[4][4];
	power(a,b/2,tmp,m);
	if(b%2==0)
	{
		mul(tmp,tmp,ans,m);
	}
	else
	{
		mul(tmp,tmp,ans,m);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				tmp[i][j]=ans[i][j];
			}
		}
		mul(a,tmp,ans,m);
	}
}
int main()
{
    int t,i,j,k;
    long int m;
    long long int n,a[4][4]={{1,1,1,0},{1,0,0,0},{0,0,1,1},{0,0,0,1}},ans[4][4],fa[4][1],mt[4][1];
    scanf("%d",&t);
    fa[0][0]=1;
    fa[1][0]=0;
    fa[2][0]=1;
    fa[3][0]=1;
    while(t--)
    {
    	scanf("%lld%ld",&n,&m);
		power(a,n-1,ans,m);
		for(i=0;i<4;i++)
		{
			for(j=0;j<1;j++)
			{
				mt[i][j]=0;
				for(k=0;k<4;k++)
				{
					mt[i][j]+=ans[i][k]*fa[k][j];
					mt[i][j]%=m;
				}
			}
		}
		if(n==0)
		{
			mt[0][0]=0;
		}
		printf("%lld\n",mt[0][0]);
    }
    return 0;
}

