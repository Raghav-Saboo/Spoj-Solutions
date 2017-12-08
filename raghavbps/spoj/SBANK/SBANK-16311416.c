#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#include <bits/stdc++.h>
int main()
{
    map <string , int> m;
    map <string , int>:: iterator it;
    int t,i,l,j,k;
    long int n,p;
    string s;
    char a[100];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(p = 1; p <= n; p++)
        {
            k=0;
            for(i = 0; i < 6; i++)
            {
                cin>>a;
                l=strlen(a);
                for(j=0;j<l;j++)
                {
                    s.push_back(a[j]);
                }
                s.push_back(' ');
            }
            m[s]++;
            s.clear();
        }
        for(it = m.begin(); it != m.end(); it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;
        m.clear();
    }
}
