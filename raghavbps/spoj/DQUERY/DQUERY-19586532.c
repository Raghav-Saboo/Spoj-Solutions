#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[30005];
int p[1000005];
int bit[30005];
int ans[200005];
struct st
{
    int r;
    int l;
    int ind;
};
struct st arr[200005];
int cmp(struct st a,struct st b)
{
    return a.r<b.r;
}
void update(int id,int x,int n)
{
    for(;id<=n;id+=id&-id)
    {
        bit[id]+=x;
    }
}
int query(int id)
{
    int an=0;
    while(id>0)
    {
        an+=bit[id];
        id-=id&-id;
    }
    return an;
}
int main()
{
    int n,i,q,l,r;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&l,&r);
        arr[i].l=l;
        arr[i].r=r;
        arr[i].ind=i;
    }
    memset(p,-1,sizeof(p));
    sort(arr+1,arr+q+1,cmp);
    int cnt=1;
    for(i=1;i<=q;i++)  
    {
        //cout<<arr[i].l<<" "<<arr[i].r<<" "<<arr[i].ind<<endl;
    }
    for(i=1;i<=n;i++)
    {
        if(p[a[i]]!=-1)
        {
            update(p[a[i]],-1,n);
        }
        p[a[i]]=i;
        update(i,1,n);
        while(cnt<=q&&arr[cnt].r==i)
        {
            ans[arr[cnt].ind]=query(arr[cnt].r)-query(arr[cnt].l-1);
            cnt++;
        }
    }
    for(i=1;i<=q;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
