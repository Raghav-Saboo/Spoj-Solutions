#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[20];
int etf[1000005];
void pre()
{
    int i,j,x,d;
    int c;
    for(i=1;i<=1e6;i++)
    {
        etf[i]=i;
    }
    for(i=2;i<=1e6;i++)
    {
        if(etf[i]==i)
        {
            for(j=i;j<=1e6;j+=i)
            {
                etf[j]/=i;
                etf[j]*=(i-1);
            }
        }
    }
    for(i=1;i<=1e6;i++)
    {
        c=0;
        x=i;
        while(x!=1)
        {
            x=etf[x];
            c++;
        }
        v[c].push_back(i);
    }
}
int main()
{
    pre();
    int t,m,n,k,ans;
    cin>>t;
    while(t--)
    {
        cin>>m>>n>>k;
        ans=(upper_bound(v[k].begin(),v[k].end(),n)-v[k].begin())-(upper_bound(v[k].begin(),v[k].end(),m-1)-v[k].begin());
        cout<<ans<<endl;
    }
    return 0;
}
