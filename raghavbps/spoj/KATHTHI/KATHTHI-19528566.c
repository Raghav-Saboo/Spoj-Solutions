#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<lli,lli>
#define mp make_pair
#define pb push_back
vector <pii> v[1000005];
lli d[1000005];
char arr[1005][1005];
lli val[1005][1005];
lli dij(lli s,lli n,lli des)
{
    lli i,t,x,y;
    deque <lli> q;
    for(i=1;i<=n;i++)
    {
        d[i]=1e9;
    }
    q.push_back(s);
    d[s]=0;
    while(!q.empty())
    {
        t=q.front();
        q.pop_front();
        for(i=0;i<v[t].size();i++)
        {
            x=v[t][i].first;
            y=v[t][i].second;
            if(d[x]>d[t]+y)
            {
                d[x]=d[t]+y;
                if(y==0)
                {
                    q.push_front(x);
                }
                else
                {
                    q.push_back(x);
                }
            }
        }
    }
    return d[des];
}
int main()
{
    lli t,i,j,k,l,r,c;
    lli ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&r,&c);
        k=0;
        for(i=0;i<r;i++)
        {
            scanf("%s",arr[i]);
            for(j=0;j<c;j++)
            {
                val[i][j]=++k;    
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if((i-1)>=0&&arr[i-1][j]==arr[i][j])
                {
                    v[val[i][j]].pb(mp(val[i-1][j],0));
                }
                else if((i-1)>=0)
                {
                    v[val[i][j]].pb(mp(val[i-1][j],1));
                }
                if((j-1)>=0&&arr[i][j-1]==arr[i][j])
                {
                    v[val[i][j]].pb(mp(val[i][j-1],0));
                }
                else if((j-1)>=0)
                {
                    v[val[i][j]].pb(mp(val[i][j-1],1));
                }
                if((i+1)<r&&arr[i+1][j]==arr[i][j])
                {
                    v[val[i][j]].pb(mp(val[i+1][j],0));
                }
                else if((i+1)<r)
                {
                    v[val[i][j]].pb(mp(val[i+1][j],1));
                }
                if((j+1)<c&&arr[i][j+1]==arr[i][j])
                {
                    v[val[i][j]].pb(mp(val[i][j+1],0));
                }
                else if((j+1)<c)
                {
                    v[val[i][j]].pb(mp(val[i][j+1],1));
                }
            }
        }
        ans=dij(1,k,k);
        printf("%lld\n",ans);
        for(i=1;i<=k;i++)
        {
            v[i].clear();
        }
    }
    return 0;
}
