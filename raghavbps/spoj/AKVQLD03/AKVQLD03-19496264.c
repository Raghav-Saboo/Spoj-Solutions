#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define lli long long int
lli bit[3*N];
lli arr[N+5];
void update(lli id,lli v,lli n)
{
    while(id<=n)
    {
        bit[id]+=v;
        id+=id&-id;
    }
}
lli query(lli id)
{
    lli ans=0;
    while(id>0)
    {
        ans+=bit[id];
        id-=id&-id;
    }
    return ans;
}
int main()
{
    lli n,q,l,r;
    string s;
    cin>>n>>q;
    while(q--)
    {
        cin>>s>>l>>r;
        if(s.compare("find")==0)
        {
            cout<<query(r)-query(l-1)<<endl;
        }
        else
        {
            update(l,r,n);
        }
    }
    return 0;
}
