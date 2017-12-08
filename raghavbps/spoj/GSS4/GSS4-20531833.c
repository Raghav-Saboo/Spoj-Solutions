#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
struct node
{
    lli sum;
}seg[4*1000005];
lli arr[1000005];
void build_tree(lli rl,lli rr,lli id)
{
    if(rl==rr)
    {
        seg[id].sum=arr[rl];
        return;
    }
    lli mid=(rl+rr)/2;
    build_tree(rl,mid,2*id);
    build_tree(mid+1,rr,2*id+1);
    seg[id].sum=seg[2*id].sum+seg[2*id+1].sum;
}
void update(lli ql,lli qr,lli rl,lli rr,lli id)
{
    if(qr<rl||rr<ql)
    {
        return;
    }
    if(seg[id].sum==rr-rl+1)
    {
        return;
    }
    if(rl==rr)
    {
        seg[id].sum=sqrt(seg[id].sum);
        return;
    }
    lli mid=(rl+rr)/2;
    update(ql,qr,rl,mid,2*id);
    update(ql,qr,mid+1,rr,2*id+1);
    seg[id].sum=seg[2*id].sum+seg[2*id+1].sum;
}
lli query(lli ql,lli qr,lli rl,lli rr,lli id)
{
    if(qr<rl||rr<ql||qr<ql)
    {
        return 0;
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
    lli n,q,i,l,r,x,v,t=1;
    while(scanf("%lld",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        build_tree(1,n,1);
        scanf("%lld",&q);
        printf("Case #%lld:\n",t);
        t++;
        while(q--)
        {
            scanf("%lld",&x);
            scanf("%lld%lld",&l,&r);
            if(l>r)
            {
                lli tmp=l;
                l=r;
                r=tmp;
            }
            if(x==0)
            {
                update(l,r,1,n,1);
            }
            else
            {
                printf("%lld\n",query(l,r,1,n,1));
            }
        }
        printf("\n");
    }
	return 0;
}
