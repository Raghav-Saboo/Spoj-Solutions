#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a1[10005];
int a2[10005];
int main()
{
    int i,n,k,x,y;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a1[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>a2[i];
    }
    for(i=1;i<n;i++)
    {
        x=a1[i]+a1[i-1];
        y=a2[i]+a2[i-1];
        if(y+a1[i]<x)
        {
            x=y+a1[i];
            a1[i]=x;
            a2[i]+=a2[i-1];
        }
        else if(x+a2[i]<y)
        {
            y=x+a2[i];
            a2[i]=y;
            a1[i]+=a1[i-1];
        }
        else
        {
            a1[i]=x;
            a2[i]=y;
        }
    }
    for(i=0;i<n;i++)
    {
        //cout<<a1[i]<<" "<<a2[i]<<endl;
    }
    for(i=n-1;i>=0;i--)
    {
        x=INT_MAX;
        y=INT_MAX;
        if(a1[i]<=k)
        {
            x=a1[i];
        }
        if(a2[i]<=k)
        {
            y=a2[i];
        }
        if(x!=INT_MAX||y!=INT_MAX)
        {
            cout<<i+1<<" "<<min(x,y)<<endl;
            break;
        }
    }
    return 0;
}
