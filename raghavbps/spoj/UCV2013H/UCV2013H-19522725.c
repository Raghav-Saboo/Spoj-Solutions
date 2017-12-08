#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int arr[255][255];
map <int,int> mp;
int vis[255][255];
void dfs_util(int i,int j,int *c,int n,int m)
{
    (*c)++;
    vis[i][j]=1;
    if((i-1)>=1&&arr[i-1][j]&&!vis[i-1][j])
    {
        dfs_util(i-1,j,c,n,m);
    }
    if((j-1)>=1&&arr[i][j-1]&&!vis[i][j-1])
    {
        dfs_util(i,j-1,c,n,m);
    }
    if((i+1)<=n&&arr[i+1][j]&&!vis[i+1][j])
    {
        dfs_util(i+1,j,c,n,m);
    }
    if((j+1)<=m&&arr[i][j+1]&&!vis[i][j+1])
    {
        dfs_util(i,j+1,c,n,m);
    }
}
void dfs(int n,int m)
{
    int i,c,j,x=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            vis[i][j]=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(arr[i][j]&&!vis[i][j])
            {
                x++;
                c=0;
                dfs_util(i,j,&c,n,m);
                mp[c]++;
            }
        }
    }
    map <int,int> :: iterator it;
    cout<<x<<endl;
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    mp.clear();
}
int main()
{
    int n,i,j,m;
    while(1)
    {
        cin>>n>>m;
        if(n==0||m==0)
        {
            break;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>arr[i][j];
            }
        }
        dfs(n,m);
    }
    return 0;
}
