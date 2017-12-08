#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[10005];
int vis[10005];
int low[10005];
int disc[10005];
int ap[10005];
int par[10005];
void dfs(int u)
{
    static int t=0;
    int c=0;
    vis[u]=1;
    disc[u]=low[u]=++t;
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            c++;
            par[v[u][i]]=u;
            dfs(v[u][i]);
            low[u]=min(low[u],low[v[u][i]]);
            if(par[u]==-1&&c>1)
            {
                ap[u]=1;
            }
            if(par[u]!=-1&&low[v[u][i]]>=disc[u])
            {
                ap[u]=1;
            }
        }
        else if(v[u][i]!=par[u])
        {
            low[u]=min(low[u],disc[v[u][i]]);
        }
    }
}
int apcal(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    int c=0;
    for(i=1;i<=n;i++)
    {
        if(ap[i]==1)
        {
            c=c+1;
        }
    }
    return c;
}
int main()
{
    int t,n,m,i,j,a,b;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)
        {
            break;
        }
        for(i=1;i<=n;i++)
        {
            vis[i]=0;
            ap[i]=0;
            par[i]=-1;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        cout<<apcal(n)<<endl;
        for(i=1;i<=n;i++)
        {
            v[i].clear();
        }
    }
    return 0;
}
