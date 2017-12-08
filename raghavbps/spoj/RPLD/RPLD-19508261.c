#include <iostream>
#include <bits/stdc++.h>
using namespace std;
set <int> s[10005];
int main()
{
    int t,n,r,i,x,y,flag,p;
    map <int,int> mp;
    cin>>t;
    for(p=1;p<=t;p++)
    {
        flag=1;
        cin>>n>>r;
        for(i=1;i<=r;i++)
        {
            cin>>x>>y;
            mp[x]++;
            s[x].insert(y);
        }
        for(i=1;i<=n;i++)
        {
            if(mp.find(i)!=mp.end())
            {
                if(mp[i]!=s[i].size())
                {
                    flag=0;
                }
            }
            s[i].clear();
        }
        if(flag)
        {
            cout<<"Scenario #"<<p<<": possible\n";
        }
        else
        {
            cout<<"Scenario #"<<p<<": impossible\n";
        }
        mp.clear();
    }
    return 0;
}
