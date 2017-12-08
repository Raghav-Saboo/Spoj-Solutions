#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005
struct node
{
    int max1;
    int max2;
};
struct node seg[4*N];
int a[N];
struct node merge(struct node a,struct node b)
{
    struct node c;
    c.max1=max(a.max1,b.max1);
    c.max2=max(min(a.max1,b.max1),max(a.max2,b.max2));
    //cout<<a.max1<<" "<<b.max1<<" "<<a.max2<<" "<<b.max2<<endl;
    return c;
}
void build_tree(int rl,int rr,int ind)
{
    if(rl==rr)
    {
        seg[ind].max1=a[rl];
        seg[ind].max2=-1;
        return;
    }
    int mid=(rl+rr)/2;
    build_tree(rl,mid,2*ind);
    build_tree(mid+1,rr,2*ind+1);
    seg[ind]=merge(seg[2*ind],seg[2*ind+1]);
}
void update(int ui,int nv,int rl,int rr,int ind)
{
    if(rl<=ui&&ui<=rr)
    {
        if(rl==rr)
        {
            seg[ind].max1=nv;
            seg[ind].max2=-1;
            return;
        }
        int mid=(rl+rr)/2;
        update(ui,nv,rl,mid,2*ind);
        update(ui,nv,mid+1,rr,2*ind+1);
        seg[ind]=merge(seg[2*ind],seg[2*ind+1]);
    }
}
int query_mx1(int ql,int qr,int rl,int rr,int ind)
{
    if(rr<ql||qr<rl||qr<ql)
    {
        return 0;
    }
    if(ql<=rl&&rr<=qr)
    {
        return seg[ind].max1;
    }
    int mid=(rl+rr)/2;
    return max(query_mx1(ql,qr,rl,mid,2*ind),query_mx1(ql,qr,mid+1,rr,2*ind+1));
}
struct node query_mx2(int ql,int qr,int rl,int rr,int ind)
{
    if(rr<ql||qr<rl||qr<ql)
    {
        struct node tmp;
        tmp.max1=tmp.max2=INT_MIN;
        return tmp;
    }
    if(ql<=rl&&rr<=qr)
    {
        return seg[ind];
    }
    int mid=(rl+rr)/2;
    return merge(query_mx2(ql,qr,rl,mid,2*ind),query_mx2(ql,qr,mid+1,rr,2*ind+1));
}
int main()
{
    int n,q,i,l,r;
    char ch;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    build_tree(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
       // cout<<q<<" ";
        //scanf("%c%d%d",&ch,&l,&r);
        cin>>ch>>l>>r;
       // cout<<ch<<" "<<l<<" "<<r<<endl;
        if(ch=='Q')
        {
            printf("%d\n",query_mx1(l,r,1,n,1)+query_mx2(l,r,1,n,1).max2);
        }
        else
        {
            update(l,r,1,n,1);
        }
    }
    return 0;
}
