#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100005];
int sqf[100005];
vector <int> v[10];
void pre()
{
    int i,j,x,c;
    for(i=2;i<=1e5;i++)
    {
        if(!a[i])
        {
            for(j=i*2;j<=1e5;j+=i)
            {
                x=j;
                c=0;
                if(!sqf[j])
                {
                    while(x%i==0)
                    {
                        x/=i;
                        c++;
                    }
                    if(c>=2)
                    {
                        sqf[j]=1;
                    }
                }
            }
        }
    }
    int cnt[10];
    for(i=1;i<=1e5;i++)
    {
        for(j=0;j<10;j++)
        {
            cnt[j]=0;
        }
        if(!sqf[i])
        {
            j=i;
            while(j>0)
            {
                cnt[j%10]++;
                j/=10;
            }
        }
        for(j=0;j<10;j++)
        {
            if(cnt[j])
            {
                v[j].push_back(i);
            }
        }
    }
    for(i=0;i<=9;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
}
int main()
{
    pre();
    int t,a,b,d;
    int ans;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>d;
        ans=(upper_bound(v[d].begin(),v[d].end(),b)-v[d].begin())-(upper_bound(v[d].begin(),v[d].end(),a-1)-v[d].begin());
        cout<<ans<<endl;
    }
    return 0;
}
