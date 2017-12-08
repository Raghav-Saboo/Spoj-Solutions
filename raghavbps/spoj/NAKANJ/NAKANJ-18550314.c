#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[65];
int arr[65][65];
int d[65];
int color[65];
void bfs(int s)
{
	int n=64;
	int i;
	for(i=1;i<=n;i++)
	{
		d[i]=1e5;
		color[i]=0;
	}
	d[s]=0;
	color[s]=1;
	queue <int> q;
	q.push(s);
	int t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<v[t].size();i++)
		{
			if(color[v[t][i]]==0)
			{
				d[v[t][i]]=d[t]+1;
				color[v[t][i]]=1;
				q.push(v[t][i]);
			}
		}
	}
}
int get(int s,int des)
{
	bfs(s);
	return d[des];
}
void pre()
{
	int i,j;
	int x=1;
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			arr[i][j]=x;
			x++;
		}
	}
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			if((i-1)>=1&&(j+2)<=8)
			{
				v[arr[i][j]].push_back(arr[i-1][j+2]);
			}
			if((i+1)>=1&&(j+2)<=8)
			{
				v[arr[i][j]].push_back(arr[i+1][j+2]);
			}
			if((i-2)>=1&&(j+1)<=8)
			{
				v[arr[i][j]].push_back(arr[i-2][j+1]);
			}
			if((i+2)>=1&&(j+1)<=8)
			{
				v[arr[i][j]].push_back(arr[i+2][j+1]);
			}
			if((i-2)>=1&&(j-1)<=8)
			{
				v[arr[i][j]].push_back(arr[i-2][j-1]);
			}
			if((i+2)>=1&&(j-1)<=8)
			{
				v[arr[i][j]].push_back(arr[i+2][j-1]);
			}
			if((i-1)>=1&&(j-2)<=8)
			{
				v[arr[i][j]].push_back(arr[i-1][j-2]);
			}
			if((i-1)>=1&&(j+2)<=8)
			{
				v[arr[i][j]].push_back(arr[i-1][j+2]);
			}
			if((i+1)>=1&&(j-2)<=8)
			{
				v[arr[i][j]].push_back(arr[i+1][j-2]);
			}
		}
	}
}
int main() {
	// your code goes here
	pre();
	int t,i,l,a,b,fa,fb;
	string s1,s2;
	cin>>t;
	while(t--)
	{
		cin>>s1>>s2;
		a=s1[0]-'a'+1;
		b=s1[1]-48;
		fa=arr[a][b];
		a=s2[0]-'a'+1;
		b=s2[1]-48;
		fb=arr[a][b];
		cout<<get(fa,fb)<<endl;
	}
	return 0;
}