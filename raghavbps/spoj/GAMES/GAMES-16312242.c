#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,flag;
    float avg;
    long int i,c,n,frac,ans;
    string s;
    cin>>t;
    while(t--)
    {
        c=0;
        n=0;
        flag=0;
        frac=1;
        cin>>s;
        for(i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == '.')
            {
                flag=1;
                break;
            }
            c++;
        }
        for(i = 0; i < s.size(); i++)
        {
            if(s[i]!='.')
            {
                n=n*10 + (s[i]-'0');
            }
        }
        if(flag)
        {
            frac=pow(10,c);
        }
        ans=frac/__gcd(n,frac);
        cout<<ans<<endl;
    }
}
