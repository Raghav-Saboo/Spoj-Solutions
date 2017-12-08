#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map <long long int,string> m;
map <string ,long long int> mh;
map <long long int,string> :: iterator it;
int main() {
	// your code goes here
	int t;
	int n;
	string s1,s2;
	long long int hv,i,l,hn;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<101;i++)
		{
			m[i]="";
		}
		while(n--)
		{
			cin>>s1;
			if((s1.substr(0,3)).compare("ADD")==0)
			{
				l=s1.size();
				s2=s1.substr(4,l-4);
				l=s2.size();
				hv=0;
				for(i=0;i<l;i++)
				{
					hv+=19*(i+1)*(s2[i]);
					hv%=101;
				}
				if(mh.find(s2)==mh.end())
				{
					if(m[hv]!="")
					{
						i=1;
						hn=hv;
						while(m[hn]!=""&&i<=20)
						{
							hn=hv+i*i+23*i;
							hn%=101;
							i++;
						}
						hv=hn;
					}
					if(i<=20)
					{
						m[hv]=s2;
						mh[s2]=hv;
					}
				}
			}
			else
			{
				l=s1.size();
				s2=s1.substr(4,l-4);
				if(mh.find(s2)!=mh.end())
				{
					m[mh[s2]]="";
					mh.erase(s2);
				}
			}
		}
		i=0;
		for(it=m.begin();it!=m.end();it++)
		{
			if(it->second!="")
			{
				i++;
			}
		}
		cout<<i<<endl;
		for(it=m.begin();it!=m.end();it++)
		{
			if(it->second!="")
			{
				cout<<it->first<<":"<<it->second<<endl;
			}
		}
		m.clear();
		mh.clear();
	}
	return 0;
}