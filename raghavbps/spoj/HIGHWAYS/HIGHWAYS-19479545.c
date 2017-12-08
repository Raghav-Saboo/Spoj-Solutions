#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define sc(x) scanf("%d",&x)
vector <pii> v[100005];
struct comp 
{
    bool operator() (const pii &a, const pii &b) 
    {
        return a.second > b.second;
    }
};
priority_queue <pii,vector<pii>,comp> pq;
int d[100005];
int vis[100005];
void dij(int s,int n)
{
    int i,t,x,y,z;
    queue <pii> q;
    for(i=1;i<=n;i++)
    {
        d[i]=1e9;
        vis[i]=0;
    }
    q.push(mp(s,0));
    d[s]=0;
    while(!q.empty())
    {
        t=q.front().first;
        x=q.front().second;
        q.pop();
        for(i=0;i<v[t].size();i++)
        {
            y=v[t][i].first;
            z=v[t][i].second;
            if(!vis[y]&&d[y]>x+z)
            {
                d[y]=x+z;
                q.push(mp(y,d[y]));
            }
        }
    }
}
int main()
{
    int ans,s,des,t,n,m,i,a,b,w;
    sc(t);
    while(t--)
    {
        sc(n);
        sc(m);
        sc(s);
        sc(des);
        for(i=1;i<=m;i++)
        {
            sc(a);
            sc(b);
            sc(w);
            v[a].pb(mp(b,w));
            v[b].pb(mp(a,w));
        }
        dij(s,n);
        if(d[des]==1e9)
        {
            printf("NONE\n");
        }
        else
        {
            printf("%d\n",d[des]);
        }
    }
    return 0;
}  