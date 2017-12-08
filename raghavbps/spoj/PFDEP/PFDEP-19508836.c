#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[105];
int ind[105];
void topo_sort(int n)
{
    int i,t;
    set <int> q;
    set <int> :: iterator it;
    for(i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.insert(i);
        }
    }
    vector <int> tp;
    while(q.size()>0)
    {
        it=q.begin();
        q.erase(it);
        t=*it;
        tp.push_back(t);
        for(i=0;i<v[t].size();i++)
        {
            ind[v[t][i]]--;
            if(ind[v[t][i]]==0)
            {
                ind[v[t][i]]=0;
                q.insert(v[t][i]);
            }
        }
    }
    for(i=0;i<tp.size();i++)
    {
        cout<<tp[i]<<" ";
    }
}
int main()
{
    int n,m,i,a,b,r,j;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>r;
        for(j=1;j<=r;j++)
        {
            cin>>b;
            v[b].push_back(a);
            ind[a]++;
        }
    }
    topo_sort(n);
    return 0;
}
