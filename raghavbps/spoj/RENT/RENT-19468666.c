#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
struct order
{
    lli s;
    lli f;
    lli g;
};
struct order arr[100005];
int cmp(struct order a,struct order b)
{
    return a.f<b.f;
}
lli dp[100005];
lli late(lli i)
{
    lli j;
    for(j=i-1;j>=0;j--)
    {
        if(arr[j].f<=arr[i].s)
        {
            return j;
        }
    }
    return -1;
}
lli rec(lli n)
{
    dp[0]=arr[0].g;
    lli i,pic,pos;
    for(i=1;i<n;i++)
    {
        pic=arr[i].g;
        pos=late(i);
        if(pos!=-1)
        {
           pic+=dp[pos]; 
        }
        dp[i]=max(pic,dp[i-1]);
    }
    return dp[n-1];
}
int main()
{
    lli t,n,i,j;
    scanf("%lld",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&arr[i].s,&arr[i].f,&arr[i].g);
            arr[i].f+=arr[i].s;
        }
        sort(arr,arr+n,cmp);
        printf("%lld\n",rec(n));
    }
    return 0;
}

