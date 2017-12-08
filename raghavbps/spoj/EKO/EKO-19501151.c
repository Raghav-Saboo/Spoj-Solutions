#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli arr[1000005];
lli ret(lli x,lli n)
{
    lli i,ans=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>x)
        {
            ans+=arr[i]-x;
        }
    }
    return ans;
}
lli binary_search(lli n,lli m)
{
    lli ans,low,high,mid;
    low=1;
    high=arr[n-1];
    while(low<=high)
    {
        mid=(low+high)/2;
        if(ret(mid,n)>=m)
        {
          // cout<<ans<<" ";
           ans=mid;
           low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
    lli n,m,i;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<binary_search(n,m);
    return 0;
}
