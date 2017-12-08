#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005];
int d[100005];
int vis[100005];
void dfs(int u,int x)
{
    d[u]=x;
    vis[u]=1;
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            dfs(v[u][i],x+1);
        }
    }
}
int main() {
	// your code goes here
	int t,c,i,a,b,x,ans,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
	        vis[i]=0;
	    }
	    for(i=1;i<n;i++)
	    {
	        cin>>a>>b;
	        v[a].push_back(b);
	        v[b].push_back(a);
	    }
	    dfs(0,0);
	    x=0;
	    for(i=0;i<n;i++)
	    {
	        if(d[i]>d[x])
	        {
	            x=i;
	        }
	    }
	    for(i=0;i<n;i++)
	    {
	        d[i]=0;
	        vis[i]=0;
	    }
	    dfs(x,0);
	    ans=0;
	    for(i=0;i<n;i++)
	    {
	        if(d[i]>d[ans])
	        {
	            ans=i;
	        }
	    }
	    if(d[ans]%2!=0)
	    {
	        cout<<d[ans]/2+1<<endl;
	    }
	    else
	    {
	        cout<<d[ans]/2<<endl;
	    }
	    for(i=0;i<n;i++)
	    {
	        v[i].clear();
	    }
	}
	return 0;
}
