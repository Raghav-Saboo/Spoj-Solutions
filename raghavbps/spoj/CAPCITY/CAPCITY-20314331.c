#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005],rv[100005];
int ind[100005];
int vis[100005];
vector <vector<int>> cc;
void dfs(int u,stack <int> &st)
{
    vis[u]=1;
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            dfs(v[u][i],st);
        }
    }
    st.push(u);
}
void rdfs(int u,vector <int> &tv)
{
    int i;
    vis[u]=1;
    tv.push_back(u);
    for(i=0;i<rv[u].size();i++)
    {
        if(!vis[rv[u][i]])
        {
            rdfs(rv[u][i],tv);
        }
    }
}
void sdfs(int u)
{
    vis[u]=1;
    int i;
    for(i=0;i<rv[u].size();i++)
    {
        if(!vis[rv[u][i]])
        {
            sdfs(rv[u][i]);
        }
    }    
}
void kosaraju(int n,int m)
{
    stack <int> st;
    int i,x,y,j;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,st);
        }
    }
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    while(!st.empty())
    {
        x=st.top();
        st.pop();
        if(vis[x]==0)
        {
            vector <int> tv;
            rdfs(x,tv);
            cc.push_back(tv);
        }
    }
    int c=0,p;
    for(i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            c++;
            p=i;
        }
    }
    if(c==1)
    {
        printf("1\n");
        printf("%d\n",p);
        return;
    }
    else if(c>1)
    {
        printf("0\n");
        return;
    }
    vector <int> ans;
    for(j=0;j<cc.size();j++)
    {
        for(i=0;i<cc[j].size()&&cc[j].size()>1;i++)
        {
            ans.push_back(cc[j][i]);
        }
    }
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    for(i=0;i<ans.size();i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
}
int main()
{
    int t,n,m,i,j,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        rv[b].push_back(a);
        ind[a]++;
    }
    kosaraju(n,m);
    return 0;
}
