#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map <long long int,long long int> mp,mpc;
int main()
{
    long long int t,x;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s>>x;
        if(s.compare("insert")==0)
        {
            mp[x]++;
           // cout<<x<<" "<<mp.size()<<endl;
            if(mp[x]==2)
            {
                mpc[2]++;
            }
        }
        else
        {
            if(mp.find(x)!=mp.end())
            {
                if(mp[x]>2)
                {
                    mp[x]--;
                }
                else if(mp[x]==2)
                {
                    if(mpc[2]>=2)
                    {
                        mpc[2]--;
                    }
                    else
                    {
                        mpc.erase(mpc.find(2));
                    }
                    mp[x]--;
                }
                else
                {
                    mp.erase(mp.find(x));
                }
            }
        }
        //cout<<mp.size()<<endl;
        if(mpc[2]>=1&&mp.size()>1)
        {
            cout<<"both\n";
        }
        else if(mpc[2]>=1)
        {
            cout<<"homo\n";
        }
        else if(mp.size()>1)
        {
            cout<<"hetero\n";
        }
        else
        {
            cout<<"neither\n";
        }
    }
    return 0;
}
