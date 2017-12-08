#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli i,t,n,r,r1,r2,flag,p;
    map <lli,lli> mp,cp;
    scanf("%lld",&t);
    for(p=1;p<=t;p++)
    {
        scanf("%lld%lld",&n,&r);
        flag=0;
        for(i=0;i<r;i++)
        {
            scanf("%lld%lld",&r1,&r2);
            mp[r1]++;
            cp[r2]++;
            if(mp.find(r2)!=mp.end())
            {
                flag=1;
            }
            if(cp.find(r1)!=cp.end())
            {
                flag=1;
            }
        }
        if(!flag)
        {
            printf("Scenario #%lld: spying\n",p);
        }
        else
        {
            printf("Scenario #%lld: spied\n",p);
        }
        mp.clear();
        cp.clear();
    }
    return 0;
}
