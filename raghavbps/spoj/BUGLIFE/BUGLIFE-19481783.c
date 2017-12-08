#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int adj[2005][2005];
int flag;
int vis[2005];
int color[2005];
void dfs(int u,int n,int colr)
{
    vis[u]=1;
    color[u]=colr;
    int i;
    for(i=1;i<=n;i++)
    {
        if(!vis[i]&&adj[u][i])
        {
            dfs(i,n,1-colr);
        }
        else if(vis[i]&&color[i]==colr&&adj[u][i])
        {
            flag=0;
        }
    }
}
int main()
{
    int t,n,m,i,j,p,a,b;
    cin>>t;
    for(p=1;p<=t;p++)
    {
        flag=1;
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                adj[i][j]=0;
            }
        }
        for(i=1;i<=m;i++)
        {
            cin>>a>>b;
            adj[a][b]=1;
            adj[b][a]=1;
        }
        memset(vis,0,sizeof(vis));
        memset(color,-1,sizeof(color));
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i,n,0);
            }
        }
        cout<<"Scenario #"<<p<<":\n";
        if(!flag)
        {
            cout<<"Suspicious bugs found!\n";
        }
        else
        {
            cout<<"No suspicious bugs found!\n";
        }
    }
    return 0;
}
