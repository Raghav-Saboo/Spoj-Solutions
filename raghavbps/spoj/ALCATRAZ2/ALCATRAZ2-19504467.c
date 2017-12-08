#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[8];
int dp[260];
vector <int> v[8];
int main()
{
    int i,p,a,b;
    for(i=1;i<=8;i++)
    {
        cin>>arr[i-1];
    }
    cin>>p;
    while(p--)
    {
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int mask,j,flag,c,ans=0;
    for(mask=1;mask<(1<<8);mask++)
    {
        flag=0;
        c=0;
        for(i=0;i<8;i++)
        {
            if(mask&(1<<i))
            {
                c+=arr[i];
                for(j=0;j<v[i].size();j++)
                {
                    if(mask&(1<<v[i][j]))
                    {
                        c=0;
                        flag=1;
                        break;
                    }
                }
            }
                if(flag)
                {
                    c=0;
                    break;
                }
                ans=max(ans,c);
        }
    }
    cout<<ans;
    return 0;
}
