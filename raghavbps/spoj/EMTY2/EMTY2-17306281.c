#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int p=1,t,i,l,nz,no,flag;
	string s;
	cin>>t;
	while(t--)
	{
		flag=1;
		cin>>s;
		nz=0;
		no=0;
		l=s.size();
		for(i=0;i<l;i++)
		{
			if(s[i]=='0')
			{
				nz++;	
			}
			else
			{
				no++;
			}
		}
		if(no==0||nz%no!=0)
		{
			flag=0;
		}
		else if(nz/no!=2)
		{
			flag=0;
		}
		else
		{
			nz=0;
			no=0;
			for(i=0;i<l;i++)
			{
				if(s[i]=='0')
				{
					no++;
				}
				else
				{
					nz+=2;
				}
				if(no>nz)
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
		{
			cout<<"Case "<<p<<": "<<"yes"<<endl;
		}
		else
		{
			cout<<"Case "<<p<<": "<<"no"<<endl;
		}
		p++;
	}
	return 0;
}