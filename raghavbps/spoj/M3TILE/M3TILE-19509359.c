#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[35];
void pre()
{
    int i;
    dp[0]=1;
    dp[1]=0;
    dp[2]=3;
    dp[3]=0;
    for(i=4;i<=30;i++)
    {
        if(i%2==0)
        {
            dp[i]=4*dp[i-2]-dp[i-4];
        }
        else
        {
            dp[i]=0;
        }
    }
}
int main()
{
    pre();
    int n;
    while(1)
    {
        cin>>n;
        if(n==-1)
        {
            break;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
