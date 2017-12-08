#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli dp[35];
void pre()
{
    int i;
    dp[1]=3;
    dp[2]=9;
    for(i=3;i<=30;i++)
    {
        dp[i]=2*dp[i-1]+dp[i-2];
    }
}
int main()
{
    pre();
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}
