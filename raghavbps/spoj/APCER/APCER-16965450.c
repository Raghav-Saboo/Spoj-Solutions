#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,m,n,a,b,c,d,e,f,j,i,x,td,vd;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		td=0;
		vd=0;
		for(i=m;i<=n;i++)
		{
			for(j=1;j<=10;j++)
			{
				d=i%100;
				c=i/100;
				f=21+(13*j-1)/5+d+floor(d/4)+floor(c/4)-2*c;
				while(f<0)
				{
					f+=7;
				}
				if(f%7==5)
				{
					vd++;
				}
			}
			for(j=11;j<=12;j++)
			{
				d=(i-1)%100;
				c=(i-1)/100;
				f=21+(13*j-1)/5+d+floor(d/4)+floor(c/4)-2*c;
				while(f<0)
				{
					f+=7;
				}
				if(f%7==5)
				{
					vd++;
				}
			}
			if(i%4!=0)
			{
				td+=365;
			}
			else if(i%100!=0)
			{
				td+=366;
			}
			else if(i%400!=0)
			{
				td+=365;
			}
			else
			{
				td+=366;
			}
		}
		x=td-vd;
		e=x/144000;
		x-=e*144000;
		d=x/7200;
		x-=d*7200;
		c=x/360;
		x-=c*360;
		b=x/20;
		x-=b*20;
		a=x/1;
		cout<<e<<"."<<d<<"."<<c<<"."<<b<<"."<<a<<endl;
	}
	return 0;
}