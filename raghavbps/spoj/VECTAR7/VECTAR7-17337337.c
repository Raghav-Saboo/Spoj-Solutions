#include <iostream>
using namespace std;
#define lli long long int
long int m=1e9+7;
lli f[50];
lli mexp(lli a,lli b)
{
    if(b==0)
    {
        return 1;
    }
    lli t=mexp(a,b/2);
    if(b%2==0)
    {
        return (t%m*t%m)%m;
    }
    else
    {
        return ((t%m*t%m)%m*a%m)%m;
    }
}
void pre()
{
    lli i;
    f[1]=1;
    f[0]=1;
    for(i=2;i<=50;i++)
    {
        f[i]=f[i-1]*i;
        f[i]%=m;
    }
}
int main()
{
    pre();
    lli t,a,b,ans,i,x;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a<25&&b<25)
        {
            ans=0;
        }
        else if(a>=24&&b>=24&&((a-b)!=2)&&(a-b)!=-2)
        {
            ans=0;
        }
        else if(a!=25&&b<24)
        {
            ans=0;
        }
        else if(b!=25&&a<24)
        {
            ans=0;
        }
        else if(a==25&&b<24)
        {
            x=a-1+b;ans=1;
            for(i=0;i<b;i++)
            {
                ans*=(x-i);
                ans%=m;
            }
            ans=(ans%m)*(mexp(f[b],m-2)%m);
            ans%=m;
        }
        else if(b==25&&a<24)
        {
            x=b-1+a;ans=1;
            for(i=0;i<a;i++)
            {
                ans*=(x-i);
                ans%=m;
            }
            ans=(ans%m)*(mexp(f[a],m-2)%m);
            ans%=m;
        }
        else if(a>23 && b>23)
        {
           x=min(a,b);
           ans=mexp(2,x-24);
           ans*=f[48];
           ans%=m;
           ans*=mexp(f[24],m-2);ans%=m;
           ans*=mexp(f[24],m-2);ans%=m;
        }
        cout<<ans%m<<endl;
    }
    return 0;
}
