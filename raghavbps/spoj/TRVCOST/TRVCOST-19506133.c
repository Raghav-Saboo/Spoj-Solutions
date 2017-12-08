#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
map <pii,int> mpp;
struct cmp
{
    bool operator()(const pii &a,const pii &b)
    {
        return a.second>b.second;
    }
};
vector <pii> v[505];
int d[505];
int vis[505];
priority_queue <pii,vector<pii>,cmp> pq;
void dij(int s,int n)
{
    int i,x,y,z,t;
    for(i=0;i<=n;i++)
    {
        d[i]=1e9;
        vis[i]=0;
    }
    d[s]=0;
    pq.push(mp(s,d[s]));
    while(!pq.empty())
    {
        x=pq.top().second;
        t=pq.top().first;
        pq.pop();
        vis[t]=1;
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
int main()
{
    int s,m,i,a,b,w,q,n=0;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        v[a].pb(mp(b,w));
        v[b].pb(mp(a,w));
    }
    cin>>s;
    dij(s,500);
    cin>>q;
    while(q--)
    {
        cin>>a;
        if(d[a]!=1e9)
        {
            cout<<d[a]<<endl;
        }
        else
        {
            cout<<"NO PATH\n";
        }
    }
    return 0;
}