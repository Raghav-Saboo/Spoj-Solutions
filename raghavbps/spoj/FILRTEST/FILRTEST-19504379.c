#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli b = 100000007; 
lli m = 1000000009;
lli h[1000005];
lli pb[1000005];
lli invb[1000005];
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
        return ((tmp*tmp)%m*(a%m))%m;
    }
}
void pre()
{
    lli i,d;
    d=mexp(b,m-2);
    pb[0]=1;
    invb[0]=1;
    for(i=1;i<=1e6;i++)
    {
        pb[i]=pb[i-1]*b;
        pb[i]%=m;
        invb[i]=invb[i-1]*d;
        invb[i]%=m;
    }
}
void init(string s)
{
    lli i,l;
    l=s.size();
    h[0]=s[0]-'a';
    for(i=1;i<l;i++)
    {
        h[i]=h[i-1]+(s[i]-'a')*pb[i];
        h[i]%=m;
    }
}
lli get_hash(lli l,lli r)
{
    lli lh,rh,ans;
    lh=(l>0)?h[l-1]:0;
    rh=h[r];
    ans=((rh-lh+m)%m)*invb[l];
    ans%=m;
    return ans;
}
int main()
{
    pre();
    lli k,i,l,x,y,ans;
    string s;
    while(1)
    {
        cin>>k>>s;
        if(k==-1)
        {
            break;
        }
        init(s);
        l=s.size();
        x=0;
        for(i=0;i<l-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                x=1;
                break;
            }
        }
     //  cout<<get_hash(0,1)<<" "<<get_hash(0,4)<<" "<<get_hash(3,4)<<endl;
        if(k<l)
        {
            ans=0;
        }
        else if(!x)
        {
            ans=k-l+1;
        }
        else
        {
            y=0;
            for(i=0;i<l-1;i++)
            {
                if(get_hash(0,0+i)==get_hash(l-1-i,l-1))
                {
                    y=i+1;
                }
            }
            //cout<<y<<" ";
            ans=(k-l)/(l-y)+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
