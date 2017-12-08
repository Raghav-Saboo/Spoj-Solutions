#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ma=10000,k;
int a[10005],d[10005],st[10005];
map <int,int> m;
map <int,int> :: iterator it;
queue <int> q;
void sieve()
{
	int i,j;
	for(i=2;i*i<ma;i++)
	{
		if(!a[i])
		{
			for(j=i*i;j<ma;j+=i)
			{
				a[j]=1;					
			}
		}
	}
	k=0;
	for(i=1000;i<ma;i++)
	{
		if(!a[i])
		{
			m[k]=i;
			k++;
		}
	}
}
int adj(int t,int i)
{
	if(m[t]==m[i])
	{
		return 1;
	}
		int flag=0;
		int x=m[t],w=m[i];
		while(x>0&&w>0)
		{
			if(x%10!=w%10)
			{
				flag++;
			}
			x/=10;
			w/=10;
		}
		if(flag==1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
}
void bfs(int s)
{
	int i,t,id;
	for(i=0;i<k;i++)
	{
		d[i]=10000;
		st[i]=0;
		if(m[i]==s)
		{
			id=i;
		}
	}
	d[id]=0;
	q.push(id);
	st[id]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<k;i++)
		{
			if(st[i]==0&&adj(t,i))
			{
				st[i]=1;
				d[i]=d[t]+1;
				q.push(i);
			}
		}
		st[t]=2;
	}
}
int main() {
	// your code goes here
	sieve();
	int t,a,b,i,id;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		bfs(a);
		for(i=0;i<k;i++)
		{
			if(m[i]==b)
			{
				id=i;
				break;
			}
		}
		if(d[id]!=10000)
		{
			cout<<d[id]<<endl;
		}
		else
		{
			cout<<"Impossible"<<endl;
		}
	}
	return 0;
}