#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
string get(lli n)
{
    if(n==0)
    {
        return "0";
    }
    else if(n==1)
    {
        return "1";
    }
    else if(n==-1)
    {
        return "11";
    }
    else if(n==2)
    {
        return "110";
    }
    else if(n==-2)
    {
        return "10";
    }
    else if(n==3)
    {
        return "111";
    }
    else if(n==-3)
    {
        return "1101";
    }
    else
    {
        string s;
        if(n<0)
        {
            if(n%2==0)
            {
                s=get((-1*n)/2)+"0";
            }
            else
            {
                s=get((-1*n)/2+1)+"1";
            }
        }
        else
        {
            if(n%2==0)
            {
                s=get((-1*n)/2)+"0";
            }
            else
            {
                s=get((-1*n)/2)+"1";
            }
        }
        return s;
    }
}
int main()
{
    lli n;
    cin>>n;
    cout<<get(n);
    return 0;
}
