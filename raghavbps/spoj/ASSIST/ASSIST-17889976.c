#include <bits/stdc++.h>
using namespace std;
int a[50005],ln[50005];
void pre()
{
	int i,j,k=1,r;
	for(i=2;i<=34000;i++)
	{
		if(!a[i])
		{
			ln[k++]=i;
			r=0;
			for(j=i+1;j<=34000;j++)
			{
				if(!a[j])
				{
					r++;
				}
				if(r==i)
				{
					a[j]=1;
					r=0;
				}
			}
		}
	}
}
int main() {
	// your code goes here
	pre();
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
		{
			break;
		}
		cout<<ln[n]<<endl;
	}
	return 0;
}