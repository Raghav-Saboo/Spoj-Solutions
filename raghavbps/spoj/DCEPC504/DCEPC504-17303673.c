#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli arr[100005];
lli mexp(lli a,lli b)
{
	if(b==0)
	{
		return 1;
	}
	lli t=mexp(a,b/2);
	if(b%2==0)
	{
		return t*t;
	}
	else
	{
		return t*t*a;
	}
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	lli t,n,k,s,i,d,x;
	char ch;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(n==1)
		{
			cout<<"Male"<<endl;
		}
		else if(n<=51)
		{
			s=mexp(2,n-1)-1+k;
			d=s;
			i=0;
			while(d>0)
			{
				arr[i++]=d;
				d/=2;
			}
			d=i;
			ch='m';
			for(i=d-1;i>=1;i--)
			{
				x=arr[i-1];
				if(2*arr[i]==x&&ch=='m')
				{
					ch='m';
				}
				else if(2*arr[i]+1==x&&ch=='m')
				{
					ch='f';
				}
				else if(2*arr[i]==x&&ch=='f')
				{
					ch='f';
				}
				else if(2*arr[i]+1==x&&ch=='f')
				{
					ch='m';
				}			
			}
			if(ch=='m')
			{
				cout<<"Male"<<endl;
			}
			else
			{
				cout<<"Female"<<endl;
			}
		}
		else
		{
			n=51;
			s=mexp(2,n-1)-1+k;
			d=s;
			i=0;
			while(d>0)
			{
				arr[i++]=d;
				d/=2;
			}
			d=i;
			ch='m';
			for(i=d-1;i>=1;i--)
			{
				x=arr[i-1];
				if(2*arr[i]==x&&ch=='m')
				{
					ch='m';
				}
				else if(2*arr[i]+1==x&&ch=='m')
				{
					ch='f';
				}
				else if(2*arr[i]==x&&ch=='f')
				{
					ch='f';
				}
				else if(2*arr[i]+1==x&&ch=='f')
				{
					ch='m';
				}			
			}
			if(ch=='m')
			{
				cout<<"Male"<<endl;
			}
			else
			{
				cout<<"Female"<<endl;
			}
		}
	}
	return 0;
} 