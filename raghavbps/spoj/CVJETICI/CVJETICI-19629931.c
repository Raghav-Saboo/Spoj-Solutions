#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int bit[100005];
#define pii pair<int,int>
vector <pii> v;
void upd(int ind,int n,int v)
{
    while(ind<=n)
    {
        bit[ind]+=v;
        ind+=(ind)&(-ind);
    }
}
void update(int l,int r,int n)
{
    upd(l,n,1);
    upd(r+1,n,-1);
}
int query(int ind,int n)
{
    int sum=0;
    while(ind>0)
    {
        sum+=bit[ind];
        ind-=(ind&(-ind));
    }
    return sum;
}
int main()
{
    int i,t,l,r,mx=0,x,y;
    map <int,int> mp;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        v.push_back(make_pair(l,r));
        mx=max(mx,l);
        mx=max(mx,r);
    }
    int ans;
    for(i=0;i<v.size();i++)
    {
        l=v[i].first;
        r=v[i].second;
        ans=0;
        x=0;
        y=0;
        if(mp.find(l)!=mp.end())
        {
            x-=mp[l];
        }
        if(mp.find(r)!=mp.end())
        {
            y-=mp[r];
        }
        x+=query(l,mx);
        y+=query(r,mx);
        if(x>0)
        {
            mp[l]+=x;
        }
        if(y>0)
        {
            mp[r]+=y;
        }
        ans+=x+y;
        cout<<ans<<endl;
        update(l+1,r-1,mx);
    }
    return 0;
}
 