#include <iostream>
#include <bits/stdc++.h>
using namespace std;
queue <long int> q;
long int ds[1000005],st[1000005],u,d;
/*int adj(long int f,long int t,long int i)
{
	if((t+u)>=1&&(t+u)<=f&&((t+u)==i))
	{
		return 1;
	}
	if((t-d)>=1&&(t-d)<=f&&((t-d)==i))
	{
		return 1;
	}
	return 0;
}*/
void bfs(long int s,long int f)
{
	long int i,t;
	for(i=1;i<=f;i++)
	{
		ds[i]=1000001;
		st[i]=0;
	}
	q.push(s);
	st[s]=1;
	ds[s]=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		i=t+u;
		if(st[i]==0&&(t+u)>=1&&(t+u)<=f&&st[i]==0)
		{
			q.push(i);
			ds[i]=ds[t]+1;
			st[i]=1;
		}
		i=t-d;
		if((t-d)>=1&&(t-d)<=f&&st[i]==0)
		{
			q.push(i);
			ds[i]=ds[t]+1;
			st[i]=1;
		}
		st[t]=2;
	}
}
int main() {
	// your code goes here
	long int f,s,g;
	cin>>f>>s>>g>>u>>d;
	bfs(s,f);
	if(ds[g]!=1000001)
	{
		cout<<ds[g]<<endl;
	}
	else
	{
		cout<<"use the stairs"<<endl; 
	}
	return 0;
}