#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long int f[100005];
void pre()
{
	long int i,c,p;
	f[0]=0;
	f[1]=1;
	f[2]=2;
	f[4]=4;
	for(i=3;i<=100000;i++)
	{
		if(i%2!=0)
		{
			f[i]=0;
		}
		else
		{
			c=0;
			p=i;
			while(p%2==0)
			{
				p/=2;
				c+=2;
			}
			f[i]=c;
		}
	}
}
int main() {
	// your code goes here
	pre();
	long int x;
	cin>>x;
	cout<<f[x]<<endl;
	return 0;
}