#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[10005];
int vis[10005];
int dfs_util(int u,int *c)
{
    vis[u]=1;
    (*c)++;
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            dfs_util(v[u][i],c);
        }
    }
}
int dfs(int n)
{
    int i,ans=0,c,j;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        c=0;
        dfs_util(i,&c);
        ans=max(ans,c);
        for(j=1;j<=n;j++)
        {
            vis[j]=0;
        }
    }
    return ans;
}
int main()
{
    int n,m,i,a,b;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
    }
    cout<<dfs(n);
    return 0;
}
