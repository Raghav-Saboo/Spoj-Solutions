#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli t,n,r,i,x,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        ans=1;
        if(n-r==0)
        {
            ans=1;
        }
        else
        {
            n--;
            r--;
            if(r>n-r)
            {
                r=n-r;
            }
            ans=1;
            for(i=1;i<=r;i++)
            {
                ans=(ans*(n-i+1))/i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
