#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[1005];
int color[1005];
void bfs(int s,int n)
{
	int i,t;
	for(i=1;i<=n;i++)
	{
		color[i]=0;
	}
	queue <int> q;
	q.push(s);
	while(!q.empty())
	{
		t=q.front();
	//	cout<<t<<" ";
		q.pop();
		for(i=0;i<v[t].size();i++)
		{
			if(color[v[t][i]]==0)
			{
				color[v[t][i]]=1;
				q.push(v[t][i]);
			}
		}
		color[t]=2;
	}
}
int main() {
	// your code goes here
	int ans,t,n,i,x,j,r;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			v[i].clear();
		}
		for(i=1;i<=n;i++)
		{
			cin>>x;
			for(j=1;j<=x;j++)
			{
				cin>>r;
				v[r].push_back(i);
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			bfs(i,n);r=0;
			for(j=1;j<=n;j++)
			{
				if(color[j]!=0)
				{
					r++;
				}
			}
			if(r==n)
			{
				ans++;
			}
		//	cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}