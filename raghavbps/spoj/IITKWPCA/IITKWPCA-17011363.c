#include <iostream>
#include <bits/stdc++.h>
using namespace std;
set <string> s;
int main() {
	// your code goes here
	int t;
	int i,l;
	char a[10005];
	string ws="";
	cin>>t;
	cin.getline(a,1);
	while(t--)
	{
		cin.getline(a,10005);
		l=strlen(a);
		for(i=0;i<l;i++)
		{
			if(a[i]!=' ')
			{
				ws+=a[i];
			}
			else if(ws!="")
			{
				//cout<<ws<<" ";
				s.insert(ws);
				ws="";
			}
		}
		if(ws!="")
		{
			s.insert(ws);
		}
		//cout<<ws<<" ";
		ws="";
		cout<<s.size()<<endl;
		s.clear();
	}
	return 0;
}