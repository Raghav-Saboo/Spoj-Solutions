#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[50005];
int val[505];
int wt[505];
int rec(int kn,int n)
{
    //cout<<kn<<" "<<n<<endl;
    int i,j;
    for(i=0;i<=kn;i++)
    {
        dp[i]=1e9;
    }
    dp[0]=0;
    for(i=0;i<=kn;i++)
    {
        for(j=0;j<n;j++)
        {
            if(wt[j]<=i)
            {
                dp[i]=min(dp[i],val[j]+dp[i-wt[j]]);
            }
        }
    }
    return dp[kn];
}
int main()
{
    int e,f,x,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>e>>f;
        f-=e;
        cin>>e;
        for(i=0;i<e;i++)
        {
            cin>>val[i]>>wt[i];
        }
        int x=rec(f,e);
        if(x!=1e9)
        {
            cout<<"The minimum amount of money in the piggy-bank is "<<x<<".\n";    
        }
        else
        {
            cout<<"This is impossible."<<endl;
        }
    }
    return 0;
}
