#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli mexp(lli a,lli b,lli m)
{
    if(b==0)
    {
        return 1;
    }
    //lli tmp=mexp(a,b/2,m);
    if(b%2==0)
    {
        return (mexp(a,b/2,m)*mexp(a,b/2,m))%m;
    }
    else
    {
        return ((mexp(a,b/2,m)*mexp(a,b/2,m))%m*(a%m))%m;
    }
}
int main()
{
    lli t,a,b,m;
  //  cin>>t;
   // while(t--)
    {
        cin>>a>>b>>m;
        cout<<mexp(a,b,m)<<endl;
    }
    return 0;
}
