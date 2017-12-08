#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli ans=0,n,arr[5005],i,j,dp[5005];
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>arr[i];
    	dp[i]=1;
    }
    for(i=1;i<n;i++)
    {
    	for(j=0;j<i;j++)
    	{
    		if(abs(arr[j])<abs(arr[i])&&(arr[i]*arr[j])<0)
    		{
    			dp[i]=max(dp[i],dp[j]+1);
    		}
    	}
    }
    for(i=0;i<n;i++)
    {
    	ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}