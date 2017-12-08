#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair< int, int >
struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};
priority_queue< pii, vector< pii >, comp > pq;
int d[100005],f[100005];
map <string,int> m;
map <string,int> :: iterator it;
vector <pair<int,int>> al[100005];
void dij(int n,int s,int des)
{
    int i,u,v,y,z;
    for(i=1;i<=n;i++)
    {
        d[i]=200001;
        f[i]=0;
    }
    d[s]=0;
    pq.push(pii(s,0));
    while(!pq.empty())
    {
        u=pq.top().first;
        pq.pop();
        if(f[u])
        {
            continue;
        }
        for(i=0;i<al[u].size();i++)
        {
            y=al[u][i].first;
            z=al[u][i].second;
            if(d[y]>d[u]+z)
            {
                d[y]=d[u]+z;
                pq.push(pii(y,d[y]));
            }
        }
        f[u]=1;
    }
}
int main()
{
    int s,n,i,p,v,c;
    string st,dt;
    scanf("%d",&s);
    while(s--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            cin>>st;
            scanf("%d",&p);
            m[st]=i;
            while(p--)
            {
                scanf("%d%d",&v,&c);
                al[i].push_back(pii(v,c));
            }
        }
        cin>>p;
        while(p--)
        {
            cin>>st>>dt;
            dij(n,m[st],m[dt]);
            printf("%d\n",d[m[dt]]);
        }
        m.clear();
        for(i=1;i<=n;i++)
        {
        	al[i].clear();
        }
    }
}
