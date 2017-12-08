#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[250005];
int d[250005];
int vis[250005];
int val[505][505];
int arr[505][505];
int bfs(int s,int n,int des)
{
    int i,t;
    for(i=1;i<=n;i++)
    {
        d[i]=1e9;
        vis[i]=0;
    }
    queue <int> q;
    q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(i=0;i<v[t].size();i++)
        {
            if(!vis[v[t][i]])
            {
                vis[v[t][i]]=1;
                d[v[t][i]]=d[t]+1;
                q.push(v[t][i]);
            }
        }
    }
    if(d[des]==1e9)
    {
        return -1;
    }
    else
    {
        return d[des];
    }
}
int main()
{
    int n,m,i,j,k=0,s,des;
    string ss;
    int l;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
            cin>>ss;
            l=ss.size();
            for(j=0;j<l;j++)
            {
                arr[i][j+1]=ss[j]-'0';
                val[i][j+1]=++k;
            }
    }
    des=val[n][m];
    s=val[1][1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if((i-arr[i][j])>=1)
            {
                v[val[i][j]].push_back(val[i-arr[i][j]][j]);
            }
            if((i+arr[i][j])<=n)
            {
                v[val[i][j]].push_back(val[i+arr[i][j]][j]);
            }
            if((j-arr[i][j])>=1)
            {
                v[val[i][j]].push_back(val[i][j-arr[i][j]]);
            }
            if((j+arr[i][j])<=m)
            {
                v[val[i][j]].push_back(val[i][j+arr[i][j]]);
            }
        }
    }
    cout<<bfs(s,k,des)<<endl;
    return 0;
}
