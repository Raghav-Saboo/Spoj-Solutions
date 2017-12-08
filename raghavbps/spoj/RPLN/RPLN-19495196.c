#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005
struct node
{
    int min;
};
int arr[N+5];
struct node seg[4*N];
void build_tree(int rl,int rr,int ind)
{
    if(rl==rr)
    {
        seg[ind].min=arr[rl];
        return;
    }
    int mid=(rl+rr)/2;
    build_tree(rl,mid,2*ind);
    build_tree(mid+1,rr,2*ind+1);
    seg[ind].min=min(seg[2*ind].min,seg[2*ind+1].min);
}
int get_answer(int ql,int qr,int rl,int rr,int ind)
{
    if(qr<rl||rr<ql||ql>qr)
    {
        return INT_MAX;
    }
    if(ql<=rl&&rr<=qr)
    {
        return seg[ind].min;
    }
    int mid=(rl+rr)/2;
    return min(get_answer(ql,qr,rl,mid,2*ind),get_answer(ql,qr,mid+1,rr,2*ind+1));
}
int main()
{
    int t,n,i,q,l,r,p;
    scanf("%d",&t);
    for(p=1;p<=t;p++)
    {
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("Scenario #%d:\n",p);
        build_tree(1,n,1);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",get_answer(l,r,1,n,1));
        }
    }
    return 0;
}