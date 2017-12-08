#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
struct node
{
    lli sum;
}seg[4*1000005];
lli lazy[4*1000005];
void build_tree(lli rl,lli rr,lli id)
{
    lazy[id]=0;
    if(rl==rr)
    {
        seg[id].sum=0;
        return;
    }
    lli mid=(rl+rr)/2;
    build_tree(rl,mid,2*id);
    build_tree(mid+1,rr,2*id+1);
    seg[id].sum=seg[2*id].sum+seg[2*id+1].sum;
}
void update(lli ql,lli qr,lli v,lli rl,lli rr,lli id)
{
    if(lazy[id]!=0)
    {
        seg[id].sum+=(lazy[id])*(rr-rl+1);
        lazy[2*id]+=lazy[id];
        lazy[2*id+1]+=lazy[id];
        lazy[id]=0;
    }
    if(qr<rl||rr<ql)
    {
        return;
    }
    if(ql<=rl&&rr<=qr)
    {
        seg[id].sum+=v*(rr-rl+1);
        lazy[2*id]+=v;
        lazy[2*id+1]+=v;
        return;
    }
    lli mid=(rl+rr)/2;
    update(ql,qr,v,rl,mid,2*id);
    update(ql,qr,v,mid+1,rr,2*id+1);
    seg[id].sum=seg[2*id].sum+seg[2*id+1].sum;
}
lli query(lli ql,lli qr,lli rl,lli rr,lli id)
{
    if(qr<rl||rr<ql||qr<ql)
    {
        return 0;
    }
    if(lazy[id]!=0)
    {
        seg[id].sum+=lazy[id]*(rr-rl+1);
        lazy[2*id]+=lazy[id];
        lazy[2*id+1]+=lazy[id];
        lazy[id]=0;
    }
    if(ql<=rl&&rr<=qr)
    {
        return seg[id].sum;
    }
    lli mid=(rl+rr)/2;
    return query(ql,qr,rl,mid,2*id)+query(ql,qr,mid+1,rr,2*id+1);
}
int main()
{
    lli n,q,i,l,r,x,v,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&q);
        build_tree(1,n,1);
        while(q--)
        {
            scanf("%lld",&x);
            if(x==0)
            {
                scanf("%lld%lld%lld",&l,&r,&v);
                update(l,r,v,1,n,1);
            }
            else
            {
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",query(l,r,1,n,1));
            }
        }
    }
	return 0;
}
