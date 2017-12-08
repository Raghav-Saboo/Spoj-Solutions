#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli m=(1e9+6)/2;
lli f[200005];
lli ifc[200005];
lli mexp(lli a,lli b,lli mod)
{
    if(b==0)
    {
        return 1;
    }
    lli tmp=mexp(a,b/2,mod);
    if(b%2==0)
    {
        return (tmp*tmp)%mod;
    }
    else
    {
        return (((tmp*tmp)%mod)*(a%mod))%mod;
    }
}
void pre()
{
    lli i;
    f[0]=1;
    ifc[0]=1;
    for(i=1;i<=200005;i++)
    {
        f[i]=f[i-1]*i;
        f[i]%=m;
        ifc[i]=ifc[i-1]*mexp(i,m-2,m);
        ifc[i]%=m;
    }
}
lli get(lli a,lli b,lli n)
{
    lli y,ans;
    y=f[2*n-1];
    y=(y*ifc[n-1])%m;
    y=(y*ifc[n])%m;
    y=(2*y)%(2*m);
    y=mexp(y,b,m*2);
    ans=mexp(a,y,2*m+1);
    return ans;
}
int main()
{
    pre();
    lli t,n,r,a,b;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&n);
        printf("%lld\n",get(a,b,n));
    }
    return 0;
}
