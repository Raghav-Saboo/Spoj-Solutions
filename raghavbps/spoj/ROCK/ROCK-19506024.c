#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[205][205];
int sw[205];
int so[205];
string s;
int memo(int i,int j)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i==j)
    {
        return dp[i][i]=s[i]-'0';
    }
    else
    {
                int k,c,swt,sot;
                swt=sw[j]-((i>0)?sw[i-1]:0);
                sot=so[j]-((i>0)?so[i-1]:0);
                if(swt>sot)
                {
                   // cout<<i<<" "<<j<<" "<<l<<endl;
                    dp[i][j]=j-i+1;
                }
                else
                {
                    c=0;
                    for(k=i;k<j;k++)
                    {
                        c=max(c,memo(i,k)+memo(k+1,j));
                    }
                    dp[i][j]=c;
                }    
                return dp[i][j];
    }
}
int main()
{
    int t,n,i,j,swt,sot,l,k,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        memset(dp,-1,sizeof(dp));
        sw[0]=s[0]-'0';
        so[0]=!(s[0]-'0');
        for(i=1;i<n;i++)
        {
            sw[i]=sw[i-1]+(s[i]-'0');
            so[i]=so[i-1]+!(s[i]-'0');
           // cout<<i<<" "<<sw[i]<<" "<<so[i]<<endl;
        }
        cout<<memo(0,n-1)<<endl;
    }
    return 0;
}
