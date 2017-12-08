#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n==1)
        {
            ch='R';
        }
        else if(n>1&&m==1)
        {
            ch='D';
        }
        else if(n%2==0&&m%2==0)
        {
            if(n==m||n<m)
            {
                ch='L';
            }
            else
            {
                ch='U';
            }
        }
        else if(n%2!=0&&m%2!=0)
        {
            if(n==m||n<m)
            {
                ch='R';
            }
            else
            {
                ch='D';
            }
        }
        else
        {
            if(n%2==0&&m%2!=0)
            {
                if(n<m)
                {
                    ch='L';
                }
                else
                {
                    ch='D';
                }
            }
            else
            {
                if(n<m)
                {
                    ch='R';
                }
                else
                {
                    ch='U';
                }
            }
        }
        cout<<ch<<endl;
    }
    return 0;
}
