#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 10005
int a[1000005];
int arr[10005];
void sieve()
{
    a[1]=1;
    int i,j;
    for(i=2;i<=1e6;i++)
    {
        if(!a[i])
        {
            for(j=i*2;j<=1e6;j+=i)
            {
                a[j]=1;
            }
        }
    }
}
int seg[4*N];
int lazy[4*N];
void build_tree(int rl,int rr,int ind)
{
    lazy[ind]=0;
    if(rl==rr)
    {
        seg[ind]=!a[arr[rl]];
        return;
    }
    int mid=(rl+rr)/2;
    build_tree(rl,mid,2*ind);
    build_tree(mid+1,rr,2*ind+1);
    seg[ind]=seg[2*ind]+seg[2*ind+1];
}
void update(int ql,int qr,int nv,int rl,int rr,int ind)
{
    if(lazy[ind]!=0)
    {
        seg[ind]=(!a[lazy[ind]])*(rr-rl+1);
        if(rl!=rr)
        {
            lazy[2*ind]=lazy[ind];
            lazy[2*ind+1]=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(qr<rl||rr<ql)
    {
        return;
    }
    if(ql<=rl&&rr<=qr)
    {
        seg[ind]=(rr-rl+1)*(!a[nv]);
        if(rl!=rr)
        {
            lazy[2*ind]=nv;
            lazy[2*ind+1]=nv;
        }
        return;
    }
    int mid=(rl+rr)/2;
    update(ql,qr,nv,rl,mid,2*ind);
    update(ql,qr,nv,mid+1,rr,2*ind+1);
    seg[ind]=seg[2*ind]+seg[2*ind+1];
}
int query(int ql,int qr,int rl,int rr,int ind)
{
    if(qr<rl||rr<ql)
    {
        return 0;
    }
    if(lazy[ind]!=0)
    {
        seg[ind]=(!a[lazy[ind]])*(rr-rl+1);
        if(rl!=rr)
        {
            lazy[2*ind]=lazy[ind];
            lazy[2*ind+1]=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(ql<=rl&&rr<=qr)
    {
        return seg[ind];
    }
    int mid=(rl+rr)/2;
    return query(ql,qr,rl,mid,2*ind)+query(ql,qr,mid+1,rr,2*ind+1);
}
int main()
{
    sieve();
    int i,t,n,tyy,x,y,v,q,m=1;
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
            scanf("%d",&tyy);
            if(tyy==0)
            {
                scanf("%d%d%d",&x,&y,&v);
                update(x,y,v,1,n,1);
            }
            else
            {
                scanf("%d%d",&x,&y);
                printf("%d\n",query(x,y,1,n,1));
            }
        }
        m++;
    }
    return 0;
}
