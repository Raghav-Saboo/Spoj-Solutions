#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,id,ans;
    map <int , int> b;
    map <int , int> bf;
    map <int , int>:: iterator it;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>id;
        cin>>m;
        b[id]++;
        for(j = 0; j < m; j++)
        {
            cin>>id;
            bf[id]++;
        }
    }
    ans=0;
    for(it = bf.begin(); it != bf.end(); it++)
    {
    	if(b.end()==b.find(it->first))
    	{
    		ans++;
    	}
    }
    cout<<ans;
}
