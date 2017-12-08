#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[4][1000005];
int get(char ch)
{
//cout<<ch<<endl;
   if(ch=='1')
   {
       return 0;
   }
   else if(ch=='8')
   {
       return 1;
   }
   else if(ch=='0')
   {
       return 2;
   }
   else
   {
       return 3;
   }
}
int main()
{
    memset(dp,0,sizeof(dp));
   string s;
   cin>>s;
   int i,l,c=0,ans=0;
   l=s.size();
   if(get(s[0])==0)
   {
        dp[get(s[0])][0]++;
   }
   for(i=1;i<l;i++)
   {
       if(s[i]=='7')
       {
           if(dp[3][i-1]||dp[2][i-1])
           {
                dp[3][i]=max(dp[3][i-1]+1,dp[2][i-1]+1);
           }
           dp[2][i]=dp[2][i-1];
           dp[1][i]=dp[1][i-1];
           dp[0][i]=dp[0][i-1];
       }
       else if(s[i]=='0')
       {
           dp[3][i]=dp[3][i-1];
           if(dp[2][i-1]||dp[1][i-1])
           {
                dp[2][i]=max(dp[2][i-1]+1,dp[1][i-1]+1);
           }
           dp[1][i]=dp[1][i-1];
           dp[0][i]=dp[0][i-1];   
       }
       else if(s[i]=='8')
       {
           dp[3][i]=dp[3][i-1];
           dp[2][i]=dp[2][i-1];
           if(dp[1][i-1]||dp[0][i-1])
           {
                dp[1][i]=max(dp[1][i-1]+1,dp[0][i-1]+1);
           }
           dp[0][i]=dp[0][i-1];           
       }
       else
       {
           dp[3][i]=dp[3][i-1];
           dp[2][i]=dp[2][i-1];
           dp[1][i]=dp[1][i-1];
           dp[0][i]=dp[0][i-1]+1;           
       }
      // cout<<i<<": "<<dp[0][i]<<" "<<dp[1][i]<<" "<<dp[2][i]<<" "<<dp[3][i]<<endl;
   }
   for(i=0;i<l;i++)
   {
       c=dp[3][i];
       ans=max(ans,c);
   }
   cout<<ans;
    return 0;
}
