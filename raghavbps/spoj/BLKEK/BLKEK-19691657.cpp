#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> pos[2];
int main() {
	// your code goes here
	int t,i,l;
	string s;
	int ans;
	cin>>t;
	while(t--)
	{
		cin>>s;
		l=s.size();
		ans=0;
		for(i=0;i<l;i++)
		{
			if(s[i]=='K')
			{
				pos[0].push_back(i);
			}
			else if(s[i]=='E')
			{
				pos[1].push_back(i);
			}
		}
		if(pos[0].size()>=2&&pos[1].size()>=1)
		{
			vector <int> :: iterator it,rt;
			int a,b;
			for(i=0;i<pos[1].size();i++)
			{
				it=lower_bound(pos[0].begin(),pos[0].end(),pos[1][i]);
				a=lower_bound(pos[0].begin(),pos[0].end(),pos[1][i])-pos[0].begin();
				rt=upper_bound(pos[0].begin(),pos[0].end(),pos[1][i]);
				b=pos[0].size()-(upper_bound(pos[0].begin(),pos[0].end(),pos[1][i])-pos[0].begin());
				if(it!=pos[0].end()&&rt!=pos[0].end())
				{
					ans+=(a*b);
				}
			}
		}
		pos[0].clear();
		pos[1].clear();
		cout<<ans<<endl;
	}
	return 0;
} 