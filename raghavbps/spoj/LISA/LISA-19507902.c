#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli dp[5005][5005];
lli no[5005];
lli op[5005];
lli mx,mn;
void rec(lli n)
{
    lli i,j,l,c,k;
    for(i=0;i<n;i++)
    {
        dp[i][i]=no[i];
    }
    for(l=2;l<=n;l++)
    {
        for(i=0;i<n-l+1;i++)
        {
            j=i+l-1;
            c=INT_MIN;
            for(k=i;k<j;k++)
            {
                if(op[k]==1)
                {
                    c=max(c,dp[i][k]*dp[k+1][j]);
                }
                else
                {
                    c=max(c,dp[i][k]+dp[k+1][j]);
                }
            }
            dp[i][j]=c;
        }
    }
    mx=dp[0][n-1];
    for(l=2;l<=n;l++)
    {
        for(i=0;i<n-l+1;i++)
        {
            j=i+l-1;
            c=INT_MAX;
            for(k=i;k<j;k++)
            {
                if(op[k]==1)
                {
                    c=min(c,dp[i][k]*dp[k+1][j]);
                }
                else
                {
                    c=min(c,dp[i][k]+dp[k+1][j]);
                }
            }
            dp[i][j]=c;
        }
    }
    mn=dp[0][n-1];
}
int main()
{
    string s;
    lli t,i,l,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>s;
        l=s.size();
        n=0;
        for(i=0;i<l;i++)
        {
            ans=0;
            while(s[i]>=48&&s[i]<=57)
            {
                ans*=10;
                ans+=(s[i]-'0');
                i++;
            }
            no[n]=ans;
            if(i<l)
            {
                if(s[i]=='+')
                {
                    op[n]=0;
                }
                else
                {
                    op[n]=1;
                }
            }
            n++;
        }
        rec(n);
        cout<<mx<<" "<<mn<<endl;
    }
    return 0;
}
