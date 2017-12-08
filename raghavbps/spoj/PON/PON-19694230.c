#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[1000005];
void sieve()
{
    lli i,j;
    a[1]=1;
    a[0]=1;
    for(i=2;i<=1e6;i++)
    {
        if(!a[i])
        {
            for(j=i*i;j<=1e6;j+=i)
            {
                a[j]=1;
            }
        }
    }
}
lli mulmod(lli a,lli b,lli c)
{
    if(b==0)
    {
        return 0;
    }
    lli tmp=mulmod(a,b/2,c);
    if(b%2==0)
    {
        return (tmp+tmp)%c;
    }
    else
    {
        return (tmp+tmp+a)%c;
    }
}
lli modulo(lli a,lli b,lli c)
{
    if(b==0)
    {
        return 1;
    }
    lli tmp=modulo(a,b/2,c);
    if(b%2==0)
    {
        return mulmod(tmp,tmp,c);
    }
    else
    {
        return mulmod(mulmod(tmp,tmp,c),a,c);
    }
}
bool Miller(lli p,lli iteration)
{
    if(p<=1000000)
    {
        return !a[p];
    }
    if(p!=2&&p%2==0)
    {
        return false;
    }
    lli s,i,a,mod,temp;
    s=p-1;
    while(s%2==0)
    {
        s/=2;
    }
    for(i=0;i<iteration;i++)
    {
        a=rand()%(p-1)+1;
        temp=s;
        mod=modulo(a,temp,p);
        while(temp!=p-1&&mod!=1&&mod!=p-1)
        {
            mod=mulmod(mod,mod,p);
            temp*=2;
        }
        if(mod!=p-1&&temp%2==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    sieve();
    lli n,i,x;
    string ans;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(Miller(x,25))
        {
            ans="YES";
        }
        else
        {
            ans="NO";
        }
        cout<<ans<<endl;
    }
    
    return 0;
}