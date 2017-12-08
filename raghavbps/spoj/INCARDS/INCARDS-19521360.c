#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define mp make_pair
#define pii pair<lli,lli>
vector <pii> v[1000005],rv[1000005];
lli d[1000005];
lli rd[1000005];
lli vis[1000005];
struct cmp
{
    bool operator()(const pii &a,const pii &b)
    {
        return a.second>b.second;
    }
};
priority_queue <pii,vector<pii>,cmp> pq;
void dij(lli s,lli n)
{
    lli i,t,x,y,z;
    for(i=1;i<=n;i++)
    {
        d[i]=1e18;
        vis[i]=0;
    }
    d[s]=0;
    pq.push(mp(s,d[s]));
    while(!pq.empty())
    {
        t=pq.top().first;
        x=pq.top().second;
        pq.pop();
        for(i=0;i<v[t].size();i++)
        {
            y=v[t][i].first;
            z=v[t][i].second;
            if(!vis[y]&&d[y]>x+z)
            {
                d[y]=x+z;
                pq.push(mp(y,d[y]));
            }
        }
    }
}
void rdij(lli s,lli n)
{
    lli i,t,x,y,z;
    for(i=1;i<=n;i++)
    {
        rd[i]=1e18;
        vis[i]=0;
    }
    rd[s]=0;
    pq.push(mp(s,rd[s]));
    while(!pq.empty())
    {
        t=pq.top().first;
        x=pq.top().second;
        pq.pop();
        for(i=0;i<rv[t].size();i++)
        {
            y=rv[t][i].first;
            z=rv[t][i].second;
            if(!vis[y]&&rd[y]>x+z)
            {
                rd[y]=x+z;
                pq.push(mp(y,rd[y]));
            }
        }
    }
}
int main()
{
    lli t,n,m,i,a,b,w,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%lld%lld%lld",&a,&b,&w);
            v[a].pb(mp(b,w));
            rv[b].pb(mp(a,w));
        }
        dij(1,n);
        rdij(1,n);
        ans=0;
        for(i=1;i<=n;i++)
        {
            ans+=d[i]+rd[i];
        }
        printf("%lld\n",ans);
        for(i=1;i<=n;i++)
        {
            v[i].clear();
            rv[i].clear();
        }
    }
    return 0;
}