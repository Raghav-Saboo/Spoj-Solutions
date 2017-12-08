#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
vector <pii> v;
int cmp(pii a,pii b)
{
    return a.first<b.first;
}
struct comp
{
    bool operator()(const pii &a,const pii &b)
    {
        return a.second<b.second;
    }
};
int main()
{
    int t,n,i,dis,fuel,x,y,ans;
    priority_queue<pii,vector<pii>,comp> pq;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }
        cin>>dis>>fuel;
        for(i=0;i<n;i++)
        {
            v[i].first=dis-v[i].first;
        }
        sort(v.begin(),v.end(),cmp);
        v.push_back(make_pair(dis,0));
        n++;
        for(i=0;i<n;i++)
        {
        //   cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        cout<<endl;
        i=0;x=fuel;y=0;
        while(i<n)
        {
            while(i<n&&v[i].first<=x)
            {
               // cout<<v[i].first<<" "<<x<<" "<<i<<endl;
                pq.push(v[i]);
                i++;
            }
          //  cout<<i<<" ";
            if(i==n)
            {
                break;
            }
            while(v[i].first>x&&!pq.empty())
            {
                x+=pq.top().second;
                pq.pop();
                ans++;
                //cout<<x<<" "<<v[i].first<<" "<<ans<<" "<<i<<" ";
            }
            //cout<<endl;
            if(v[i].first>x&&pq.empty())
            {
               // cout<<v[i].first<<" "<<i<<" how\n";
                ans=-1;
                break;
            }
            if(i==n-1)
            {
                break;
            }
        }
        cout<<ans<<endl;
        while(!pq.empty())
        {
            pq.pop();
        }
        v.clear();
    }
    return 0;
}
