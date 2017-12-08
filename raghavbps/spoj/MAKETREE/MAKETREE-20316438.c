#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005];
int vis[100005];
stack <int> st;
vector <int> ts;
int ans[100005];
void dfs(int u)
{
    vis[u]=1;
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            dfs(v[u][i]);
        }
    }
    st.push(u);
}
void topo(int n,int k)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    while(!st.empty())
    {
        ts.push_back(st.top());
        st.pop();
    }
    ans[ts[0]]=0;
    int prev=ts[0];
    for(i=1;i<ts.size();i++)
    {
        ans[ts[i]]=prev;
        prev=ts[i];
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\n",ans[i]);
    }
}
int main()
{
    int n,k,i,a,b,x;
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&x);
        while(x--)
        {
            scanf("%d",&a);
            v[i].push_back(a);
        }
    }
    topo(n,k);
    return 0;
}