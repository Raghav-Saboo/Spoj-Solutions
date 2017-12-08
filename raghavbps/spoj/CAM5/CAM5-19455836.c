#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int par[100005];
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
void uni(int a,int b)
{
    int pa,pb;
    pa=fp(a);
    pb=fp(b);
    if(pa!=pb)
    {
        par[pa]=pb;
    }
}
int main()
{
    int i,t,n,a,b,ans,e;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        make_set(n);
        cin>>e;
        while(e--)
        {
            cin>>a>>b;
            a++;
            b++;
            uni(a,b);
        }
        for(i=1;i<=n;i++)
        {
            if(fp(i)==i)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
