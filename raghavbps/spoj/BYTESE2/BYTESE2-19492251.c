#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int s;
    int f;
};
struct node arr[105];
int cmp(struct node a,struct node b)
{
    return a.s<b.s;
}
int main()
{
    set <int> :: iterator it;
    int n,t,i,ans,x,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i].s>>arr[i].f;
        }
        for(i=0;i<n;i++)
        {
            x=0;
            for(j=0;j<n;j++)
            {
                if(arr[j].s<=arr[i].s&&arr[i].s<=arr[j].f)
                {
                    x++;
                }
            }
            ans=max(ans,x);
        }
        cout<<ans<<endl;
    }
    return 0;
}
