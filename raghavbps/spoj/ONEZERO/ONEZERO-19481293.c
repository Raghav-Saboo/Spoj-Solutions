#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
map <int,string> mp;
int sm(string s,int m)
{
    int i,ans,l;
    l=s.size();
    ans=0;
    for(i=0;i<l;i++)
    {
        ans*=10;
        ans+=s[i]-'0';
        ans%=m;
    }
    return ans;
}
string bfs(int n)
{
    queue <string> q;
    mp[1]="1";
    string ans="1";
    q.push(ans);
    int md,vis[n+1];
    memset(vis,-1,sizeof(vis));
    while(vis[0]==-1)
    {
        ans=q.front();
        q.pop();
        md=sm(ans,n);
        if(vis[md]==-1)
        {
            mp[md]=ans;
            vis[md]=1;
            q.push(ans+"0");
            q.push(ans+"1");
        }
    }
    return mp[0];
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<bfs(n)<<endl;
        mp.clear();
    }
    return 0;
}
