#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int vis[5005];
vector <int> v[5005],rv[5005];
vector <vector<int>> scc;
void dfs_util(vector<int> &tv,int u)
{
    int i;
    vis[u]=1;
    tv.push_back(u);
    for(i=0;i<rv[u].size();i++)
    {
        if(!vis[rv[u][i]])
        {
            dfs_util(tv,rv[u][i]);
        }
    }
}
void dfs(stack <int> &st,int u)
{
    vis[u]=1;
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            dfs(st,v[u][i]);
        }
    }
    st.push(u);
}
void kosaraju(int n)
{
    int i,j,x,y;
    stack <int> st;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(st,i);
        }
    }
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    while(!st.empty())
    {
        i=st.top();
        st.pop();
     //  cout<<i<<" ";
        if(!vis[i])
        {
            vector <int> tv;
            dfs_util(tv,i);
            scc.push_back(tv);
        }
    }
    for(i=0;i<scc.size();i++)
    {
        sort(scc[i].begin(),scc[i].end());
    }
    set <int> s;
    for(i=0;i<scc.size();i++)
    {
        y=0;
        for(j=0;j<scc[i].size();j++)
        {
            for(x=0;x<v[scc[i][j]].size();x++)
            {
                if(!binary_search(scc[i].begin(),scc[i].end(),v[scc[i][j]][x]))
                {
                    y=1;
                    break;
                }
            }
            if(y==1)
            {
                break;
            }
        }
        if(!y)
        {
            for(j=0;j<scc[i].size();j++)
            {
                s.insert(scc[i][j]);
            }
        }
    }
    set <int> :: iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    i=scc.size();
    for(j=0;j<i;j++)
    {
        scc[j].clear();
    }
}
int main()
{
    int n,m,i,a,b;
    while(1)
    {
        cin>>n;
        if(!n)
        {
            break;
        }
        cin>>m;
        for(i=1;i<=m;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            rv[b].push_back(a);
        }
        kosaraju(n);
        for(i=1;i<=n;i++)
        {
            v[i].clear();
            rv[i].clear();
        }
    }
    return 0;
}
