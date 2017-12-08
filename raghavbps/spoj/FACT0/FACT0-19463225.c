#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli n;
    while(1)
    {
        cin>>n;
        if(n==0)
        {
            break;
        }
        lli i,c,j,x;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                c=0;
                while(n%i==0)
                {
                    c++;
                    n/=i;
                }
                cout<<i<<"^"<<c<<" ";
            }
        }
        if(n>1)
        {
            cout<<n<<"^"<<"1 ";
        }
        cout<<endl;
    }
    return 0;
}
