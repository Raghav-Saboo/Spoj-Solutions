#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map <string,int> mpw;
map <string,int> mpl;
int main()
{
    int c,g1,g2,i;
    map <string,int> :: iterator it;
    string s1,s2;
    cin>>c;
    while(c--)
    {
        for(i=1;i<=16;i++)
        {
            cin>>s1>>s2>>g1>>g2;
            if(g1>g2)
            {
                mpw[s1]++;
                mpl[s2]++;
            }
            else
            {
                mpw[s2]++;
                mpl[s1]++;
            }
        }
        for(it=mpw.begin();it!=mpw.end();it++)
        {
            //cout<<it->first<<" ";
            if(mpl.find(it->first)==mpl.end())
            {
                cout<<it->first<<endl;
            }
        }
        mpw.clear();
        mpl.clear();
    }
    return 0;
}
