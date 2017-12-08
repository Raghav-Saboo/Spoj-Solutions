#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const lli N=(1<<20)+5;
lli dp[N];
lli arr[25][25];
lli rec(lli n)
{
    memset(dp,0,sizeof(dp));
    dp[(1<<n)-1]=1;
    lli i,j;
    for(i=(1<<n)-1;i>=0;i--)
    {
        lli x=__builtin_popcount(i);
        for(j=0;j<n;j++)
        {
            if(arr[x][j]==0||(i&(1<<j)))
            {
                continue;
            }
            dp[i]+=dp[i|(1<<j)];
        }
    }
    return dp[0];
}
int main()
{
    lli t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>arr[i-1][j-1];
            }
        }
        cout<<rec(n)<<endl;
    }
    return 0;
}