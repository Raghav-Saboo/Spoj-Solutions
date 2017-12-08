#include <bits/stdc++.h>
using namespace std;
stack <char> st;
int get(string s)
{
	int i,l;
	l=s.size();
	if(l%2!=0)
	{
		return -1;
	}
	int ans=0;
	for(i=0;i<l;i++)
	{
		if(s[i]=='{')
		{
			st.push(s[i]);
		}
		else
		{
			if(st.empty())
			{
				s[i]='{';
				st.push(s[i]);
				ans++;
			}
			else
			{
				st.pop();
			}
		}
	}
	ans+=st.size()/2;
	while(!st.empty())
	{
		st.pop();
	}
	return ans;
}
int main() {
	
	//relevant code here
	string s;
	int t=1;
	while(1)
	{
		cin>>s;
		if(s[0]=='-')
		{
			break;
		}
		cout<<t<<". "<<get(s)<<endl;
		t++;
	}
	return 0;
}