#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 50000
#define lint long long int
struct node
{
    lint answer,pref_sum,suff_sum,total_sum;
};
struct node seg[4*N];
int arr[N+5];
struct node merge(struct node x,struct node y)
{
    struct node z;
    lint c=y.pref_sum+x.suff_sum;
    z.answer=max(x.answer,max(y.answer,c));
    z.pref_sum=max(x.pref_sum,x.total_sum+y.pref_sum);
    z.suff_sum=max(y.suff_sum,y.total_sum+x.suff_sum);
    z.total_sum=x.total_sum+y.total_sum;
    return z;
}
void build_tree(int rl,int rr,int ind)
{
    if(rl==rr)
    {
        //cout<<rl<<endl;
        seg[ind].answer=arr[rl];
        seg[ind].pref_sum=arr[rl];
        seg[ind].suff_sum=arr[rl];
        seg[ind].total_sum=arr[rl];
        return;
    }
    int mid=(rl+rr)/2;
    build_tree(rl,mid,2*ind);
    build_tree(mid+1,rr,2*ind+1);
    seg[ind]=merge(seg[2*ind],seg[2*ind+1]);
   // cout<<ind<<" "<<seg[ind].total_sum<<endl;
}
struct node get_answer(int ql,int qr,int rl,int rr,int ind)
{
    if(qr<rl||rr<ql||qr<ql)
    {
        struct node tmp;
        tmp.answer=tmp.pref_sum=tmp.suff_sum=INT_MIN;
        return tmp;
    }
    if(ql<=rl&&rr<=qr)
    {
        return seg[ind];
    }
    else
    {
        int mid=(rl+rr)/2;
        return merge(get_answer(ql,qr,rl,mid,2*ind),get_answer(ql,qr,mid+1,rr,2*ind+1));
    }
}
int main()
{
    int n,i,q,l,r;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    build_tree(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&l,&r);
        printf("%lld\n",get_answer(l,r,1,n,1).answer);
    }
    return 0;
}
