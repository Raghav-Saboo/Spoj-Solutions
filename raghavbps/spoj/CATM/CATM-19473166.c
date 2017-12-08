#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int val[105][105];
map <int,int> mp[4];
vector <int> v[10005];
int md[10005];
int cd[2][10005];
void mbfs(int s,int n)
{
    int i,t;
    int vis[10005];
    memset(md,100000,sizeof(vis));
    memset(vis,0,sizeof(vis));
    queue <int> q;
    md[s]=0;
    q.push(s);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(i=0;i<v[t].size();i++)
        {
            if(!vis[v[t][i]])
            {
                vis[v[t][i]]=1;
                md[v[t][i]]=md[t]+1;
                q.push(v[t][i]);
            }
        }
    }
}
void cbfs(int s,int n,int y)
{
    int i,t;
    int vis[10005];
    memset(cd[y],100000,sizeof(vis));
    memset(vis,0,sizeof(vis));
    queue <int> q;
    cd[y][s]=0;
    q.push(s);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(i=0;i<v[t].size();i++)
        {
            if(!vis[v[t][i]])
            {
                vis[v[t][i]]=1;
                cd[y][v[t][i]]=cd[y][t]+1;
                q.push(v[t][i]);
            }
        }
    }
}
int main()
{
    int i,j,t,n,m,k,x1,y1,x2,y2,x3,y3,flag;
    cin>>n>>m;
    cin>>t;
    k=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            val[i][j]=++k;
            if(i==1)
            {
              mp[0][k]++;  
            }
            else if(j==1)
            {
                mp[2][k]++;
            }
            else if(i==n)
            {
              mp[1][k]++;  
            }
            else if(j==m)
            {
              mp[3][k]++;  
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if((i-1)>=1)
            {
                v[val[i][j]].push_back(val[i-1][j]);
            }
            if((j-1)>=1)
            {
                v[val[i][j]].push_back(val[i][j-1]);
            }
            if((i+1)<=n)
            {
                v[val[i][j]].push_back(val[i+1][j]);
            }
            if((j+1)<=m)
            {
                v[val[i][j]].push_back(val[i][j+1]);
            }
        }
    }
    map <int,int> :: iterator it;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        mbfs(val[x1][y1],k);
        cbfs(val[x2][y2],k,0);
        cbfs(val[x3][y3],k,1);
        flag=0;
        for(i=0;i<4;i++)
        {
            for(it=mp[i].begin();it!=mp[i].end();it++)
            {
                if(md[it->first]<cd[0][it->first]&&md[it->first]<cd[1][it->first])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
