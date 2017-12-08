#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 100005
#define lint long long int
int inc;
struct node
{
    lint ps,ss,pv,sv,mfv,mfc;
};
struct node seg[4*N];
int arr[N+5];
struct node merge(struct node x,struct node y)
{
    struct node z;
    lint p=0;
    if(x.sv==y.pv)
    {
        p=x.ss+y.ps;
        p/=x.sv;
    }
    z.mfc=max(max(x.mfc,y.mfc),p);
    if(z.mfc==p)
    {
        z.mfv=x.sv;
    }
    else if(z.mfc==x.mfc)
    {
        z.mfv=x.mfv;
    }
    else
    {
        z.mfv=y.mfv;
    }
    if(x.sv==y.pv&&x.pv==x.sv)
    {
        z.pv=x.pv;
        z.ps=x.ps+y.ps;
    }
    else
    {
        z.pv=x.pv;
        z.ps=x.ps;
    }
    if(y.sv==y.pv&&x.sv==y.sv)
    {
        z.sv=y.pv;
        z.ss=y.ss+x.ss;
    }
    else
    {
        z.sv=y.sv;
        z.ss=y.ss;
    }
    return z;
}
void build_tree(int rl,int rr,int ind)
{
    if(rl==rr)
    {
        //cout<<rl<<endl;
        seg[ind].mfv=arr[rl];
        seg[ind].mfc=1;
        seg[ind].ps=arr[rl];
        seg[ind].ss=arr[rl];
        seg[ind].pv=arr[rl];
        seg[ind].sv=arr[rl];
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
        tmp.mfc=0;
        tmp.mfv=INT_MIN+inc;
        tmp.ps=INT_MIN+inc;
        tmp.pv=INT_MIN+inc;
        tmp.ss=INT_MIN+inc;
        tmp.sv=INT_MIN+inc;
        inc++;
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
    int n,i,q,l,r,t;
    while(1)
    {
        scanf("%d",&n);
        if(!n)
        {
            break;
        }
        scanf("%d",&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        build_tree(1,n,1);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%lld\n",get_answer(l,r,1,n,1).mfc);
        }
    }
    return 0;
}
