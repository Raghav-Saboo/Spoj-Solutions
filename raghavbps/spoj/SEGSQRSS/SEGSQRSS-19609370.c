#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005
int arr[100005];
struct node
{
  int sum;
  int sq;
};
struct node seg[4*N];
struct ty
{
    int typ;
    int v;
};
struct ty lazy[4*N];
int n;
void build_tree(int rl,int rr,int ind)
{
    lazy[ind].v=0;
    lazy[ind].typ=0;
    if(rl==rr)
    {
        seg[ind].sq=arr[rl]*arr[rl];
        seg[ind].sum=arr[rl];
        return;
    }
    int mid=(rl+rr)/2;
    build_tree(rl,mid,2*ind);
    build_tree(mid+1,rr,2*ind+1);
    seg[ind].sq=seg[2*ind].sq+seg[2*ind+1].sq;
    seg[ind].sum=seg[2*ind].sum+seg[2*ind+1].sum;
}
int query(int ql,int qr,int rl,int rr,int ind,int u)
{
    if(qr<rl||rr<ql)
    {
        return 0;
    }
    if(lazy[ind].v!=0&&lazy[ind].typ==1)
    {
        seg[ind].sq=(lazy[ind].v*lazy[ind].v)*(rr-rl+1);
        seg[ind].sum=(lazy[ind].v)*(rr-rl+1);
        if(rl!=rr)
        {
            lazy[2*ind]=lazy[ind];
            lazy[2*ind+1]=lazy[ind];
        }
        lazy[ind].v=0;
        lazy[ind].typ=0;
    }
    else if(lazy[ind].v!=0&&lazy[ind].typ==2)
    {
        seg[ind].sq+=(lazy[ind].v*lazy[ind].v)*(rr-rl+1)+2*lazy[ind].v*query(rl,rr,1,n,1,0);
        seg[ind].sum+=(lazy[ind].v)*(rr-rl+1);
        if(rl!=rr)
        {
            lazy[2*ind]=lazy[ind];
            lazy[2*ind+1]=lazy[ind];
        }
        lazy[ind].v=0;
        lazy[ind].typ=0;
    }
    if(ql<=rl&&rr<=qr)
    {
        if(u)
        {
            return seg[ind].sq;
        }
        else
        {
            return seg[ind].sum;
        }
    }
    int mid=(rl+rr)/2;
    return query(ql,qr,rl,mid,2*ind,u)+query(ql,qr,mid+1,rr,2*ind+1,u);
}
void update1(int ql,int qr,int nv,int rl,int rr,int ind)
{
    if(lazy[ind].v!=0&&lazy[ind].typ==1)
    {
        seg[ind].sq=(lazy[ind].v*lazy[ind].v)*(rr-rl+1);
        seg[ind].sum=(lazy[ind].v)*(rr-rl+1);
        if(rl!=rr)
        {
            lazy[2*ind]=lazy[ind];
            lazy[2*ind+1]=lazy[ind];
        }
        lazy[ind].v=0;
        lazy[ind].typ=0;
    }
    else if(lazy[ind].v!=0&&lazy[ind].typ==2)
    {
        seg[ind].sq+=(lazy[ind].v*lazy[ind].v)*(rr-rl+1)+2*lazy[ind].v*query(rl,rr,1,n,1,0);
        seg[ind].sum+=(lazy[ind].v)*(rr-rl+1);
        if(rl!=rr)
        {
            lazy[2*ind]=lazy[ind];
            lazy[2*ind+1]=lazy[ind];
        }
        lazy[ind].v=0;
        lazy[ind].typ=0;
    }
    if(qr<rl||rr<ql)
    {
        return;
    }
    if(ql<=rl&&rr<=qr)
    {
        seg[ind].sq=(rr-rl+1)*(nv*nv);
        seg[ind].sum=(rr-rl+1)*nv;
        if(rl!=rr)
        {
            lazy[2*ind].v=nv;
            lazy[2*ind+1].v=nv;
            lazy[2*ind].typ=1;
            lazy[2*ind+1].typ=1;
        }
        return;
    }
    int mid=(rl+rr)/2;
    update1(ql,qr,nv,rl,mid,2*ind);
    update1(ql,qr,nv,mid+1,rr,2*ind+1);
    seg[ind].sq=seg[2*ind].sq+seg[2*ind+1].sq;
    seg[ind].sum=seg[2*ind].sum+seg[2*ind+1].sum;
}
void update2(int ql,int qr,int nv,int rl,int rr,int ind)
{
    if(lazy[ind].v!=0&&lazy[ind].typ==1)
    {
        seg[ind].sq=(lazy[ind].v*lazy[ind].v)*(rr-rl+1);
        seg[ind].sum=(lazy[ind].v)*(rr-rl+1);
        if(rl!=rr)
        {
            lazy[2*ind]=lazy[ind];
            lazy[2*ind+1]=lazy[ind];
        }
        lazy[ind].v=0;
        lazy[ind].typ=0;
    }
    else if(lazy[ind].v!=0&&lazy[ind].typ==2)
    {
        seg[ind].sq+=(lazy[ind].v*lazy[ind].v)*(rr-rl+1)+2*lazy[ind].v*query(rl,rr,1,n,1,0);
        seg[ind].sum+=(lazy[ind].v)*(rr-rl+1);
        if(rl!=rr)
        {
            lazy[2*ind]=lazy[ind];
            lazy[2*ind+1]=lazy[ind];
        }
        lazy[ind].v=0;
        lazy[ind].typ=0;
    }
    if(qr<rl||rr<ql)
    {
        return;
    }
    if(ql<=rl&&rr<=qr)
    {
        seg[ind].sq+=(rr-rl+1)*(nv*nv)+2*nv*query(rl,rr,1,n,1,0);
        seg[ind].sum+=(rr-rl+1)*nv;
        if(rl!=rr)
        {
            lazy[2*ind].v=nv;
            lazy[2*ind+1].v=nv;
            lazy[2*ind].typ=2;
            lazy[2*ind+1].typ=2;
        }
        return;
    }
    int mid=(rl+rr)/2;
    update2(ql,qr,nv,rl,mid,2*ind);
    update2(ql,qr,nv,mid+1,rr,2*ind+1);
    seg[ind].sq=seg[2*ind].sq+seg[2*ind+1].sq;
    seg[ind].sum=seg[2*ind].sum+seg[2*ind+1].sum;
}
int main()
{
    int i,t,ty,x,y,v,q,m=1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",m);
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        build_tree(1,n,1);
        while(q--)
        {
            scanf("%d",&ty);
            if(ty==0)
            {
                scanf("%d%d%d",&x,&y,&v);
                update1(x,y,v,1,n,1);
            }
            else if(ty==1)
            {
                scanf("%d%d%d",&x,&y,&v);
                update2(x,y,v,1,n,1);
            }
            else
            {
                scanf("%d%d",&x,&y);
                printf("%d\n",query(x,y,1,n,1,1));
            }
        }
        m++;
    }
    return 0;
}