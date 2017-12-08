#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli d[1005][1005];
lli mod=pow(2,31)-1;
char adj[1005][1005];
int vis[1005][1005];
#define pii pair<lli,lli>
int bfs(lli n)
{
    lli x,y;
    queue<pii> q;
    q.push(make_pair(1,1));
    while(!q.empty())
    {
        pii p=q.front();
        q.pop();
        x=p.first;
        y=p.second;
        if(x-1>=1&&!vis[x-1][y]&&adj[x-1][y]!='#')
        {
            vis[x-1][y]=1;
            q.push(make_pair(x-1,y));
        }
        if(y-1>=1&&!vis[x][y-1]&&adj[x][y-1]!='#')
        {
            vis[x][y-1]=1;
            q.push(make_pair(x,y-1));
        }
        if(x+1<=n&&!vis[x+1][y]&&adj[x+1][y]!='#')
        {
            vis[x+1][y]=1;
            q.push(make_pair(x+1,y));
        }
        if(y+1<=n&&!vis[x][y+1]&&adj[x][y+1]!='#')
        {
            vis[x][y+1]=1;
            q.push(make_pair(x,y+1));
        }
    }
    return vis[n][n];
}
int main()
{
    string s;
    lli n,i,j,ans,m;
    cin>>n;
    m=n;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        for(j=1;j<=n;j++)
        {
            adj[i][j]=s[j-1];
        }
    }
    d[1][1]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i-1>=1&&adj[i-1][j]!='#')
            {
                d[i][j]+=d[i-1][j];
                d[i][j]%=mod;
            }
            if(j-1>=1&&adj[i][j-1]!='#')
            {
                d[i][j]+=d[i][j-1];
                d[i][j]%=mod;
            }
        }
    }
    if(d[n][m]!=0)
    {
        cout<<d[n][m]<<endl;
    }
    else
    {
        if(bfs(n))
        {
            cout<<"THE GAME IS A LIE\n";
        }
        else
        {
            cout<<"INCONCEIVABLE\n";
        }
    }
    return 0;
}
