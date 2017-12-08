#include <bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
int block_size=10000;
int limit=block_size+1;
vector <int> v;
int main()
{
	int i,j,x,c=0;
	a[0]=1;
	a[1]=1;
	for(i=2;i<=1e4;i++)
	{
		if(!a[i])
		{
			c++;
			if(c%100==1)
			{
				printf("%d\n",i);
			}
			v.push_back(i);
			for(j=i*2;j<=1e4;j+=i)
			{
				a[j]=1;
			}
		}
	}
	int low,high;
	low=limit;
	high=2*limit;
	while(low<1e8)
	{
		for(i=0;i<limit;i++)
		{
			b[i]=0;
		}
		for(i=0;i<v.size();i++)
		{
			x=(low/v[i])*v[i];
			if(x<low)
			{
				x+=v[i];
			}
			for(j=x;j<high;j+=v[i])
			{
				b[j-low]=1;
			}
		}
		for(i=0;i<limit;i++)
		{
			if(!b[i])
			{
				c++;
				if(c%100==1&&i+low<1e8)
				{
					printf("%d\n",i+low);
				}
			}
		}
		low+=limit;
		high+=limit;
		if(high>1e8)
		{
			high=1e8;
		}
	}
	return 0;
}