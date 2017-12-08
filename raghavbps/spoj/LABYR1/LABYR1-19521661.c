#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define mp make_pair
#define pii pair<lli,lli>
vector <lli> v[1000005];
lli vis[1000005];
char arr[1005][1005];
lli val[1005][1005];
lli d[1000005];
lli bfss(lli s,lli n)
{
    queue <lli> q;
    lli i,t;
    q.push(s);
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        d[i]=-1;
    }
    vis[s]=1;
    d[s]=0;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(i=0;i<v[t].size();i++)
        {
            if(!vis[v[t][i]])
            {
                vis[v[t][i]]=1;
                q.push(v[t][i]);
                d[v[t][i]]=d[t]+1;
            }
        }
    }
    lli mx=0,p=-1;
    for(i=1;i<=n;i++)
    {
        if(mx<d[i])
        {
            mx=d[i];
            p=i;
        }
    }
    if(mx==0)
    {
        return 0;
    }
    return mx;
}
lli bfs(lli s,lli n)
{
    queue <lli> q;
    lli i,t;
    q.push(s);
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        d[i]=-1;
    }
    vis[s]=1;
    d[s]=0;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(i=0;i<v[t].size();i++)
        {
            if(!vis[v[t][i]])
            {
                vis[v[t][i]]=1;
                q.push(v[t][i]);
                d[v[t][i]]=d[t]+1;
            }
        }
    }
    lli mx=0,p=-1;
    for(i=1;i<=n;i++)
    {
        if(mx<d[i])
        {
            mx=d[i];
            p=i;
        }
    }
    if(mx==0)
    {
        return 0;
    }
    return p;
}
int main()
{
    lli t,n,m,i,k,ans,j,s;
    scanf("%lld",&t);
    while(t--)
    {
        k=0;
        scanf("%lld%lld",&m,&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",arr[i]);
            for(j=0;j<m;j++)
            {
                val[i][j]=++k;
                if(arr[i][j]=='.')
                {
                    s=k;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]=='.')
                {
                    if((i-1)>=0&&arr[i-1][j]=='.')
                    {
                        v[val[i][j]].pb(val[i-1][j]);
                    }
                    if((j-1)>=0&&arr[i][j-1]=='.')
                    {
                        v[val[i][j]].pb(val[i][j-1]);
                    }
                    if((i+1)<n&&arr[i+1][j]=='.')
                    {
                        v[val[i][j]].pb(val[i+1][j]);
                    }
                    if((j+1)<m&&arr[i][j+1]=='.')
                    {
                        v[val[i][j]].pb(val[i][j+1]);
                    }
                }
            }
        }
        lli g=bfs(s,k);
        if(g!=0)
        {
            g=bfss(g,k);
        }
        printf("Maximum rope length is %lld.\n",g);
        for(i=1;i<=k;i++)
        {
            v[i].clear();
        }
    }
    return 0;
}