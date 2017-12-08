#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lcs[5005][5005];
int get(string a,string b)
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
                lcs[i][j]=0;
            }
            else if(a[i-1]!=b[j-1])
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
            else
            {
                lcs[i][j]=1+lcs[i-1][j-1];
            }
        }
    }
    return n-lcs[m][n];
}
int main()
{
    int l;
    string a;
    string b;
    cin>>l>>a;
    b=a;
    reverse(a.begin(),a.end());
    cout<<get(a,b)<<endl;
    return 0;
}
