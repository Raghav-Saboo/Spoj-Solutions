#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,n;
    double x,y,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            ans=2/3.0;
        }
        else
        {
            x=3/4.0;
            y=1/(2.0*(n+1)*(n+2));
            ans=x-y;
        }
        printf("%.11lf\n",ans);
    }
    return 0;
}
