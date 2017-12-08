#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct trie
{
	struct trie *c[10];
	int lf;
};
set <string> st;
set <string> :: iterator it;
int flag;
struct trie * getnode()
{
	struct trie *p;
	p=(struct trie *)malloc(sizeof(struct trie));
	int i;
	for(i=0;i<=9;i++)
	{
		p->c[i]=NULL;
	}
	p->lf=0;
	return p;
}
void insert(struct trie *root,string x)
{
	struct trie *t=root;
	int i,l;
	l=x.size();
	for(i=0;i<l;i++)
	{
		if(t!=NULL&&t->c[x[i]-'0']==NULL)
		{
			t->c[x[i]-'0']=getnode();
		}
		if(t!=NULL)
		{
			t=t->c[x[i]-'0'];
		}
		if(t->lf==1)
		{
			flag=0;
		}
	}
	t->lf=1;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		struct trie *root=getnode();
		int n,q,i;
		string s;
		int l;
		flag=1;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>s;
			st.insert(s);
			//insert(root,s);
		}
		for(it=st.begin();it!=st.end();it++)
		{
			insert(root,*it);
		}
		st.clear();
		if(flag)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
} 