#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
vector <pii> v[10005],rv[10005],rvv[10005];
int vis[10005];
int rd[10005];
int rdg[10005];
int ans;
struct cmp
{
    bool operator()(const pii &a,const pii &b)
    {
        return a.second>b.second;
    }
};
priority_queue <pii,vector<pii>,cmp> pq;
void rdij(int s,int n)
{
    int i,t,x,y,z;
    for(i=1;i<=n;i++)
    {
        rdg[i]=1e9;
        vis[i]=0;
    }
    pq.push(mp(s,0));
    rdg[s]=0;
    while(!pq.empty())
    {
        t=pq.top().first;
        x=pq.top().second;
        pq.pop();
        vis[t]=1;
        for(i=0;i<rvv[t].size();i++)
        {
            y=rvv[t][i].first;
            z=rvv[t][i].second;
            if(!vis[y]&&rdg[y]>x+z)
            {
                rdg[y]=x+z;
                pq.push(mp(y,rdg[y]));
            }
        }
    }
}
void ndij(int s,int n,int des)
{
    int i,t,x,y,z;
    for(i=1;i<=n;i++)
    {
        rd[i]=1e9;
        vis[i]=0;
    }
    pq.push(mp(s,0));
    rd[s]=0;
    while(!pq.empty())
    {
        t=pq.top().first;
        x=pq.top().second;
        pq.pop();
        vis[t]=1;
        if(t==des)
        {
            ans=min(ans,rd[des]);
        }
        for(i=0;i<v[t].size();i++)
        {
            y=v[t][i].first;
            z=v[t][i].second;
            if(!vis[y]&&rd[y]>x+z)
            {
                rd[y]=x+z;
                pq.push(mp(y,rd[y]));
            }
        }
        for(i=0;i<rv[t].size();i++)
        {
            y=rv[t][i].first;
            z=rv[t][i].second;
            ans=min(ans,rd[t]+z+rdg[y]);    
        }
    }
}
int main()
{
    int des,n,m,k,s,t,a,b,w,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>s>>des;
        ans=1e9;
        for(i=1;i<=m;i++)
        {
            cin>>a>>b>>w;
            v[a].pb(mp(b,w));
            rvv[b].pb(mp(a,w));
        }
        for(i=1;i<=k;i++)
        {
            cin>>a>>b>>w;
            rv[a].pb(mp(b,w));
            rv[b].pb(mp(a,w));
        }
        rdij(des,n);
        ndij(s,n,des);
        if(ans==1e9)
        {
            ans=-1;
        }
        cout<<ans<<endl;
        for(i=1;i<=n;i++)
        {
            v[i].clear();
            rvv[i].clear();
            rv[i].clear();
        }
    }
    return 0;
}
