#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005];
int d[100005];
int vis[100005];
void dfs(int u,stack <int> &st)
{
    vis[u]=1;
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            dfs(v[u][i],st);
        }
    }
    st.push(u);
}
int main() {
	// your code goes here
	vector <int> ts;
	int j,t,c,i,a,b,x,ans,n,src,des,m;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m>>src>>des;
	    for(i=1;i<=n;i++)
	    {
	        vis[i]=0;
	        d[i]=0;
	    }
	    for(i=1;i<=m;i++)
	    {
	        cin>>a>>b;
	        v[a].push_back(b);
	    }
	    d[src]=1;
	    stack <int> st;
	    dfs(src,st);
	    while(!st.empty())
	    {
	        ts.push_back(st.top());
	        st.pop();
	    }
	    for(i=0;i<ts.size();i++)
	    {
	        for(j=0;j<v[ts[i]].size();j++)
	        {
	            d[v[ts[i]][j]]+=d[ts[i]];
	            d[v[ts[i]][j]]%=1000000007;
	        }
	    }
	    cout<<d[des]<<endl;
	    for(i=1;i<=n;i++)
	    {
	        //cout<<i<<" "<<d[i]<<endl;
	        v[i].clear();
	    }
	    ts.clear();
	}
	return 0;
}
