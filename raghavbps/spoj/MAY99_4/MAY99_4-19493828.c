#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli m=10000007;
lli pb=9988440;
lli f[1005];
void pre()
{
    f[0]=1;
    lli i;
    for(i=1;i<=1000;i++)
    {
        f[i]=f[i-1]*i;
        f[i]%=m;
    }
}
lli mexp(lli a,lli b)
{
    if(b==0)
    {
        return 1;
    }
    lli tmp=mexp(a,b/2);
    if(b%2==0)
    {
        return (tmp*tmp)%m;
    }
    else
    {
        return (((tmp*tmp)%m)*(a%m))%m;
    }
}
lli get(lli n,lli r)
{
    lli i,x;
    if(n<r)
    {
        return -1;
    }
  ///  cout<<n<<" "<<f[n]<<" "<<r<<" "<<f[r]<<endl;
    x=(f[n]*(mexp(f[n-r],pb-1)))%m;
    x=(x*mexp(f[r],pb-1))%m;
    return x;
}
int main()
{
    pre();
    lli n,r;
    cin>>n>>r;
    n-=r;
    cout<<get(n+r-1,r-1);
    return 0;
}
