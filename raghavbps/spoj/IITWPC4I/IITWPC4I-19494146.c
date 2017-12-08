#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lint long long int
struct edge
{
    lint a;
    lint b;
    lint w;
};
lint ans;
map <lint,lint> mp;
lint par[300005];
struct edge arr[300005];
int cmp(struct edge x,struct edge y)
{
    return x.w<y.w;
}
void make_set(lint n)
{
    lint i;
    for(i=1;i<=n;i++)
    {
        par[i]=i;
    }
}
int fp(lint x)
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
void uni(lint a,lint b,lint w)
{
    lint pa,pb;
    pa=fp(a);
    pb=fp(b);
    if(pa!=pb)
    {
      //  cout<<a<<" "<<b<<" "<<w<<endl;
        if(mp.find(pa)!=mp.end())
        {
            par[pb]=pa;
        }
        else
        {
            par[pa]=pb;
        }
        ans+=w;
    }
}
int main()
{
    lint t,n,m,i,x;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(x)
            {
                mp[i]++;
            }
        }
        for(i=1;i<=m;i++)
        {
            cin>>arr[i-1].a>>arr[i-1].b>>arr[i-1].w;
        }
        sort(arr,arr+m,cmp);
        make_set(n);
        for(i=0;i<m;i++)
        {
            if(mp.find(fp(arr[i].a))==mp.end()||mp.find(fp(arr[i].b))==mp.end())
            {
                uni(arr[i].a,arr[i].b,arr[i].w);
            }
        }
        x=0;
        for(i=1;i<=n;i++)
        {
            if(mp.find(fp(i))==mp.end())
            {
                x=1;
                break;
            }
        }
        if(!x)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<"impossible\n";
        }
        mp.clear();
    }
    return 0;
}
