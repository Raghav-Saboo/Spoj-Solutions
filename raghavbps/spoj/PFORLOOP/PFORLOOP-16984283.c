#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
vector <pair<lli,lli>> v;
vector <pair<lli,lli>> :: iterator vit;
set <lli> s;
set <lli> ::iterator it1;
set <lli> ::iterator it2;
int main() {
	// your code goes here
	lli n,cd,f=0;
	lli a,b,ma,mb;
	while(scanf("%lld",&n)!=EOF)
	{
		s.insert(n);
	}
	it1=s.begin();
	it2=it1;
	it1++;
	a=*it2;
	b=*it1;
	cd=1;
	ma=a;
	f=0;
	for(;it1!=s.end();it2=it1,it1++)
	{
		a=*it2;
		b=*it1;
		if(b-a!=1)
		{
			v.push_back(make_pair(ma,a));
			ma=b;
		}
	}
	v.push_back(make_pair(ma,*it2));	
	for(vit=v.begin();vit!=v.end();vit++)
	{
		printf("for (int i = %lld; i <= %lld; i++) cout << i << \" \";\n",vit->first,vit->second);
	}
	v.clear();
	s.clear();
	return 0;
}