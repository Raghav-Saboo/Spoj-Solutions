#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
map <int,int> mp;
int flag[1005];
int main()
{
    int n,i,j,t=1;
    while(1)
    {
        cin>>n;
        if(!n)
        {
            break;
        }
        for(i=1;i<=n;i++)
        {
            flag[i]=0;
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        for(i=1;i<=n;i++)
        {
            mp[b[i]]=i;
        }
        int ans=0;
        vector <int> tv;
        int mn;
        for(i=1;i<=n;i++)
        {
            if(mp[a[i]]!=i&&!flag[i])
            {
                j=i;
                mn=1e4;
                do
                {
                    mn=min(mn,a[j]);
                    tv.push_back(a[j]);
                    flag[j]=1;
                    j=mp[a[j]];
                }while(i!=j);
                int sx=0,sm=0;
                for(j=0;j<tv.size();j++)
                {
                    if(tv[j]!=mn)
                    {
                        sm=sm+tv[j];
                    }
                }
                sx=sm+(tv.size()-1)*mn;
                int sy=0;
                sy=sm+(tv.size()-1)*b[1]+2*(b[1]+mn);
                ans=ans+min(sx,sy);
                tv.clear();
            }
        }
        mp.clear();
        cout<<"Case "<<t<<": "<<ans<<endl;
        t++;
    }
    return 0;
}
