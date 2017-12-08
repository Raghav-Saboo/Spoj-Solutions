#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int a;
    int b;
    int w;
};
int ans;
struct edge arr[1000005];
int par[10005];
int cmp(struct edge x,struct edge y)
{
    return x.w<y.w;
}
void make_set(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        par[i]=i;
    }
}
int fp(int x)
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
void uni(int a,int b,int w)
{
    int pa,pb;
    pa=fp(a);
    pb=fp(b);
    if(pa!=pb)
    {
        par[pa]=pb;
        ans+=w;
    }   
}
int main()
{
    int s,n;
    string ss;
    int p,neg,cst,i,e;
    cin>>s;
    while(s--)
    {
        ans=0;
        cin>>n;e=0;
        for(i=1;i<=n;i++)
        {
            cin>>ss;
            cin>>p;
            while(p--)
            {
                cin>>neg>>cst;
                arr[e].a=i;
                arr[e].b=neg;
                arr[e].w=cst;
                e++;
            }
        }
        make_set(n);
        sort(arr,arr+e,cmp);
        for(i=0;i<e;i++)
        {
            uni(arr[i].a,arr[i].b,arr[i].w);
        }
        cout<<ans<<endl;
    }
    return 0;
}
