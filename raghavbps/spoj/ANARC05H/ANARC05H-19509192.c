#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int rec(string s,int id,int prv)
{
    if(id==s.size())
    {
        return 1;
    }
//    cout<<id<<" "<<prv<<endl;
    int x,i,l;
    l=s.size();
    x=s[id]-'0';
    i=id+1;
    for(;i<l&&x<prv;i++)
    {
        x+=s[i]-'0';
    }
  //  cout<<i<<" "<<prv<<" "<<x<<endl;
    if(i==l&&x>=prv)
    {
        return 1;
    }
    int ans=0;
    if(x>=prv)
    {
        for(;i<l;i++)
        {
            ans+=rec(s,i,x);
            x+=s[i]-'0';
        }
        ans+=rec(s,i,x);
    }
 //   cout<<ans<<" ";
    return ans;
}
int main()
{
    string s;
    int k=1;
    while(1)
    {
        cin>>s;
        if(s.compare("bye")==0)
        {
            break;
        }
        cout<<k<<". "<<rec(s,0,0)<<endl;
        k++;
    }
    return 0;
}
