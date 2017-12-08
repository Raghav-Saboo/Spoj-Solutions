#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int at[15],dt[15];
int main() {
	// your code goes here
	int a,d,i,mn,mx;
	while(1)
	{
		cin>>a>>d;
		if(a==0&&d==0)
		{
			break;
		}
		mn=10005;
		for(i=0;i<a;i++)
		{
			cin>>at[i];
			if(mn>at[i])
			{
				mn=at[i];
			}
		}
		for(i=0;i<d;i++)
		{
			cin>>dt[i];
		}
		sort(dt,dt+d);
		//cout<<mn<<" ";
		if(dt[0]<=mn&&dt[1]<=mn)
		{
			cout<<"N"<<endl;
		}
		else
		{
			cout<<"Y"<<endl;
		}
	}
	return 0;
}