#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int ics[1005],dcs[1005];
int main()
{
    int t,n,i,ans,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            ics[i]=1;
            dcs[i]=1;
        }
        for(i=1;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j]&&ics[i]<ics[j]+1)
                {
                    ics[i]=ics[j]+1;
                }
            }
        }
        for(i=0;i<n/2;i++)
        {
            j=arr[i];
            arr[i]=arr[n-1-i];
            arr[n-1-i]=j;
        }
        for(i=1;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j]&&dcs[i]<dcs[j]+1)
                {
                    dcs[i]=dcs[j]+1;
                }
            }
        }
        for(i=0;i<n;i++)
        {
        //    cout<<i<<" "<<ics[i]<<" "<<dcs[i]<<endl;
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            ans=max(ans,ics[i]+dcs[n-1-i]-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
