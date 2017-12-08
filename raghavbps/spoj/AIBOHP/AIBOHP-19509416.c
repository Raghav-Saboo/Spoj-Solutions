#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[6105][6105];
int lcs_str(string a,string b)
{
    int i,j,m,n;
    m=a.size();
    n=b.size();
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string s,r;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        r=s;
        reverse(r.begin(),r.end());
        cout<<s.size()-lcs_str(s,r)<<endl;
    }
    return 0;
}
