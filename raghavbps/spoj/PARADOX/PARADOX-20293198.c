#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector <pii> v[105];
vector <pii> rv[105];
int vis[105];
int ans;
vector <int> chk;
stack <int> ks;
void sdfs(int u)
{
    if(chk.size()<=1)
    {
        return;
    }
    int as=v[chk[0]][0].second;
    int x=u,i;
    for(i=0;i<chk.size();i++)
    {
        //cout<<chk[i]<<" ";
    }
    //cout<<endl;
    for(i=1;i<chk.size();i++)
    {
        if(as==1)
        {
            as=v[chk[i]][0].second;
        }
        else
        {
            as=1-v[chk[i]][0].second;
        }
        //cout<<as<<" "<<chk[i]<<endl;
    }
    if(as!=1)
    {
        ans=1;
    }
}
void dfs(int u)
{
    vis[u]=1;
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i].first])
        {
            dfs(v[u][i].first);
        }
    }
    //cout<<u<<" "<<endl;
    ks.push(u);
}
void rdfs(int u)
{
    vis[u]=1;
    chk.push_back(u);
    int i;
    for(i=0;i<rv[u].size();i++)
    {
        if(!vis[rv[u][i].first])
        {
            rdfs(rv[u][i].first);
        }
    }
}
void kos(int n)
{
    int i,u;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    while(!ks.empty())
    {
        u=ks.top();
        ks.pop();
        if(vis[u]==0)
        {
            chk.clear();
            //cout<<u<<endl;
            rdfs(u);
            sdfs(u);
        }
    }
}
int main()
{
    int n,i,a,d;
    char s[105];
    while(1)
    {
        scanf("%d",&n);
        ans=0;
        d=1;
        if(n==0)
        {
            break;
        }
        for(i=1;i<=n;i++)
        {
            vis[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d%s",&a,s);
            if(strcmp(s,"true")==0)
            {
                v[i].push_back(make_pair(a,1));
                rv[a].push_back(make_pair(i,1));
            }
            else
            {
                if(i==a)
                {
                    d=0;
                }
                v[i].push_back(make_pair(a,0));
                rv[a].push_back(make_pair(i,0));
            }
        }
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        kos(n);
        if(ans==1||d==0)
        {
            printf("PARADOX\n");
        }
        else
        {
            printf("NOT PARADOX\n");
        }
        for(i=1;i<=n;i++)
        {
            v[i].clear();
            rv[i].clear();
        }
    }
    return 0;
}