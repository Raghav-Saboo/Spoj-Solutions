#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli b = 100000007; 
lli m = 1000000009;
lli h[100005];
lli arr[100005];
lli pb[100005];
lli invb[100005];
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
lli init()
{
    lli i,x;
    x=mexp(b,m-2);
    pb[0]=1;
    invb[0]=1;
    for(i=1;i<=1e5;i++)
    {
        pb[i]=pb[i-1]*b;
        pb[i]%=m;
        invb[i]=invb[i-1]*x;
        invb[i]%=m;
    }
}
void ha_sh(string s)
{
    lli i,l;
    l=s.size();
    h[0]=s[0]-'A';
    for(i=1;i<l;i++)
    {
        h[i]=h[i-1]+(s[i]-'A')*pb[i];
        h[i]%=m;
    }
}
lli sub_hash(lli l,lli r)
{
    lli rh,lh,ans;
    rh=h[r];
    lh=(l>0)?h[l-1]:0;
    ans=(rh-lh+m)*invb[l];
    ans%=m;
    return ans;
}
int main()
{
    init();
    string g,s;
    lli t,n,i,l,x,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        s="";
        for(i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            {
                s+="G";
            }
            else if(arr[i]<arr[i-1])
            {
                s+="L";
            }
            else
            {
                s+="E";
            }
        }
        ha_sh(s);
       // cout<<s<<endl;
        cin>>g;
        x=g[0]-'A';
        l=g.size();
        for(i=1;i<l;i++)
        {
            x=x+(g[i]-'A')*pb[i];
            x%=m;
        }
        ans=0;
        for(i=0;i<n-l;i++)
        {
            if(x==sub_hash(i,i+l-1))
            {
                ans=1;
            }
        }
        if(ans)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
