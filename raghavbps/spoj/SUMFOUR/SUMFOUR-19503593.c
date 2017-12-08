#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
int arr[2550][4];
unordered_map <int,int> mp;
int main()
{
    int low,high,mid,cnt,x,n,i,j,sb=0,ans=0,foc,loc;
    sc(n);
    mp.reserve(2*n*n);
    //int *barr=(int *)malloc((n*n+5)*sizeof(int));
    for(i=0;i<n;i++)
    {
        sc(arr[i][0]);
        sc(arr[i][1]);
        sc(arr[i][2]);
        sc(arr[i][3]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            mp[arr[i][2]+arr[j][3]]++;
            //barr[sb++]=arr[i][2]+arr[j][3];
        }
    }
    //sort(barr,barr+sb);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            x=arr[i][0]+arr[j][1];
            x*=-1;
           /* low=0;
            high=sb-1;
            foc=-1;
            loc=-1;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(barr[mid]==x)
                {
                    foc=mid;
                    high=mid-1;
                }
                else if(barr[mid]>x)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            low=0;
            high=sb-1;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(barr[mid]==x)
                {
                    loc=mid;
                    low=mid+1;
                }
                else if(barr[mid]>x)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            if(loc!=-1&&foc!=-1)
            {
                cnt=loc-foc+1;
            }
            else
            {
                cnt=0;
            }
           // cout<<x<<" "<<cnt<<endl;*/
           if(mp.find(x)!=mp.end())
           {
            ans+=mp[x];
           }
        }
    }
    printf("%d\n",ans);
    return 0;
}
