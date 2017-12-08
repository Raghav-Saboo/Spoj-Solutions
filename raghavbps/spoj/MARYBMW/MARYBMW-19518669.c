#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<lli,lli>
#define pb push_back
map <pii,lli> mp;
vector <lli> v[50005];
struct edge
{
    lli a;
    lli b;
    lli w;
};
int cmp(struct edge x,struct edge y)
{
    return x.w>y.w;
}
struct edge arr[100005];
lli par[50005];
lli vis[50005];
lli bfs(lli n)
{
    lli i,t,s=1;
    for(i=1;i<=n;i++)
    {
        par[i]=-1;
        vis[i]=0;
    }
    queue <lli> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        //cout<<t<<" ";
        for(i=0;i<v[t].size();i++)
        {
            //cout<<v[t][i]<<" "<<vis[v[t][i]]<<endl;
            if(!vis[v[t][i]])
            {
                q.push(v[t][i]);
                vis[v[t][i]]=1;
                par[v[t][i]]=t;
            }
        }
    }
    if(par[n]==-1)
    {
        return -1;
    }
    lli ans=1e18;
    t=n;
    while(t!=1)
    {
        //cout<<t<<" "<<par[t]<<endl;
        ans=min(ans,mp[make_pair(t,par[t])]);
        t=par[t];
    }
    return ans;
}
void make_set(lli n)
{
    lli i;
    for(i=1;i<=n;i++)
    {
        par[i]=i;
    }
}
lli fp(lli x)
{
    if(x==par[x])
    {
        return x;
    }
    else
    {
        return par[x]=fp(par[x]);
    }
}
void uni(lli a,lli b,lli w)
{
    //cout<<a<<" "<<b<<" "<<sz+1<<endl;
    lli pa,pb;
    pa=fp(a);
    pb=fp(b);
    if(pa!=pb)
    {
        v[a].pb(b);
        v[b].pb(a);
        par[pa]=pb;
        mp[make_pair(a,b)]=w;
        mp[make_pair(b,a)]=w;
        //cout<<a<<" "<<b<<" "<<endl;
    }
}
int main()
{
    lli t,n,m,a,b,w,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%lld%lld%lld",&arr[i-1].a,&arr[i-1].b,&arr[i-1].w);
        }
        sort(arr,arr+m,cmp);
        make_set(n);
       // cout<<m<<endl;
        for(i=0;i<m;i++)
        {
            uni(arr[i].a,arr[i].b,arr[i].w);
        }
        printf("%lld\n",bfs(n));
        for(i=1;i<=n;i++)
        {
            v[i].clear();
        }
        mp.clear();
    }
    return 0;
}