#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
char arr[105][105];
int val[105][105];
vector <int> v[10005],tmp;
map <int,char> mp;
string ans;
int vis[10005];
int pref(string a,string b)
{
	int i,l;
	string pf="";
	l=b.size();
	for(i=0;i<l;i++)
	{
		pf+=b[i];
		if(pf.compare(a)==0)
		{
			return 1;
		}
	}
	return 0;
}
void dfs_visit(int u,string s)
{
	tmp.pb(u);
    vis[u]=1;
    s+=mp[u];
  //  cout<<s<<endl;
    if(s.compare("ALLIZZWELL")==0)
    {
        ans="YES";
        return;
    }
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(pref(s+mp[v[u][i]],"ALLIZZWELL")&&vis[v[u][i]]==0)
        {
            dfs_visit(v[u][i],s);
        }
    }
    if(ans.compare("YES")!=0)
    {
        vis[u]=0;
    }
}
void dfs(int n)
{
	memset(vis,0,sizeof(vis));
    int i;
     //cout<<n<<endl;
    for(i=1;i<=n;i++)
    {
        if(mp[i]=='A'&&ans.compare("YES")!=0)
        {
           	int j;
           	for(j=0;j<tmp.size();j++)
           	{
           		vis[tmp[i]]=0;
           	}
           	tmp.clear();
            dfs_visit(i,"");
        }
    }
}
int main()
{
    int t,r,c,i,j;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
       // cout<<r<<" "<<c<<endl;
        ans="NO";
        int k=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cin>>arr[i][j];
                val[i][j]=++k;
                mp[k]=arr[i][j];
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                
                {
                    if((i+1)<r)
                    {
                        v[val[i][j]].pb(val[i+1][j]);
                    }
                    if((i-1)>=0)
                    {
                         v[val[i][j]].pb(val[i-1][j]);
                    }
                    if((j+1)<c)
                    {
                         v[val[i][j]].pb(val[i][j+1]);
                    }
                    if((j-1)>=0)
                    {
                         v[val[i][j]].pb(val[i][j-1]);
                    }
                    if((i+1)<r&&(j+1)<c)
                    {
                         v[val[i][j]].pb(val[i+1][j+1]);
                    }
                    if((i-1)>=0&&(j+1)<c)
                    {
                         v[val[i][j]].pb(val[i-1][j+1]);
                    }
                    if((i+1)<r&&(j-1)>=0)
                    {
                         v[val[i][j]].pb(val[i+1][j-1]);
                    }
                    if((i-1)>=0&&(j-1)>=0)
                    {
                         v[val[i][j]].pb(val[i-1][j-1]);
                    }
                }
            }
        }
      //  cout<<k<<endl;
        dfs(k);
        cout<<ans<<endl;
       // cout<<k<<endl;
        for(i=1;i<=k;i++)
        {
            v[i].clear();
        }
        mp.clear();
    }
    return 0;
}