#include <bits/stdc++.h>
using namespace std;
#define N 100000
int a[N];
int seg[4*N];
void build(int rl,int rr,int ind)
{
    if(rl==rr)
    {
        seg[ind]=a[rl];
        return;
    }
    int mid=(rl+rr)/2;
    build(rl,mid,2*ind);
    build(mid+1,rr,2*ind+1);
    seg[ind]=min(seg[2*ind],seg[2*ind+1]);
}
int query(int rl,int rr,int ql,int qr,int id)
{
    if(ql>rr||rl>qr||rl>rr)
    {
        return INT_MAX;
    }
    if(ql<=rl&&rr<=qr)
    {
        return seg[id];
    }
    int mid=(rl+rr)/2;
    return min(query(rl,mid,ql,qr,2*id),query(mid+1,rr,ql,qr,2*id+1));
}
int main()
{
    int i,t,n;
    int q,l,r;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,n,1);
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        l++;
        r++;
        cout<<query(1,n,l,r,1)<<endl;
    }
    return 0;
}