#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ma[50][50],d[500];
int adj[405][405];
char ch[50][50],st[1000];
queue <int> q;
map <int,int> mp;
map <int,int> :: iterator it;
void bfs(int n,int s)
{
	int i,t;
	for(i=1;i<=n;i++)
	{
		st[i]=0;
		d[i]=1000;
	}
	q.push(s);
	d[s]=0;
	st[s]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=1;i<=n;i++)
		{
			if(st[i]==0&&adj[t][i]!=0)
			{
				st[i]=1;
				q.push(i);
				d[i]=d[t]+1;
			}
		}
		st[t]=2;
	}
}
int main() {
	// your code goes here
	int t,m,n,i,j,c,flag;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		c=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>ch[i][j];
				ma[i][j]=++c;
				if((j==0||j==n-1||i==0||i==m-1)&&ch[i][j]=='.')
				{
					mp[ma[i][j]]++;
				}
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(ch[i][j]=='.')
				{
					if((i+1)>=0&&(i+1)<m&&ch[i+1][j]!='#')
					{
						adj[ma[i][j]][ma[i+1][j]]=1;
					}
					if((i-1)>=0&&(i-1)<m&&ch[i-1][j]!='#')
					{
						adj[ma[i][j]][ma[i-1][j]]=1;
					}
					if((j+1)>=0&&(j+1)<n&&ch[i][j+1]!='#')
					{
						adj[ma[i][j]][ma[i][j+1]]=1;
					}
					if((j-1)>=0&&(j-1)<n&&ch[i][j-1]!='#')
					{
						adj[ma[i][j]][ma[i][j-1]]=1;
					}
				}
			}
		}
		flag=0;
		if(mp.size()!=2)
		{
			flag=0;
		}
		else
		{
			it=mp.begin();
			bfs(c,it->first);
			it++;
			if(d[it->first]==1000)
			{
				flag=0;
			}
			else
			{
				flag=2;
			}
		}
		//cout<<mp.size()<<" "<<flag<<" ";
		if(flag!=2)
		{
			cout<<"invalid"<<endl;
		}
		else
		{
			cout<<"valid"<<endl;
		}
		mp.clear();
		for(i=1;i<=c;i++)
		{
			for(j=1;j<=c;j++)
			{
				adj[i][j]=0;	
			}
		}
	}
	return 0;
} 