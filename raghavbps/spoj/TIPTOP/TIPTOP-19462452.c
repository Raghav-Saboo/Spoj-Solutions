#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli i,t,x,low,high,mid,ans;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>x;
        ans=-1;
        low=1;
        high=1e9;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(mid*mid==x)
            {
                ans=mid;
                break;
            }
            else if(mid*mid<x)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(ans==-1)
        {
            cout<<"Case "<<i<<": No\n";
        }
        else
        {
            cout<<"Case "<<i<<": Yes\n";
        }
    }
    return 0;
}
