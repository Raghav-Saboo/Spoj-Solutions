#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1000005],w[1000005];
void pre()
{
	int i,x,d=0,j;
	for(i=1;i<=1e6;i++)
	{
		x=sqrt(i);
		if(x*x==i)
		{
			a[d++]=i;
		}
	}
	w[1]=1;
	w[3]=1;
	w[4]=1;
	for(i=6;i<=1e6;i++)
	{
		for(j=0;a[j]<=i;j++)
		{
			if(!w[i-a[j]])
			{
				w[i]=1;
				break;
			}
		}
	}
}
int main() {
	// your code goes here
	pre();
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(w[n])
		{
			printf("Win\n");
		}
		else
		{
			printf("Lose\n");
		}
	}
	return 0;
}