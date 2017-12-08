#include <bits/stdc++.h>
using namespace std;
#define N 100000
#define ln 30
#define sc(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
#define pii pair<int,int>
#define mp make_pair
vector <pii> adj[N];
int par[N];
int val[N];
int subsize[N];
int lev[N];
int p[N][ln];
int vis[N];
//vector <int> indx[N];
int arr[N];
vector <int> seg[4*N];
int ptr=1;
int posinbase[N];
int chainsize[N],chainhead[N],chainpos[N],chainind[N],chainno=0;
void build(int id,int rl,int rr)
{
    if(rl==rr)
    {
    	seg[id].push_back(arr[rl]);
    	return;
    }
    int mid=(rl+rr)/2;
    build(2*id,rl,mid);
    build(2*id+1,mid+1,rr);
    int i,j;
    i=0;
    j=0;
    int k=0;
    while(i<seg[2*id].size()&&j<seg[2*id+1].size())
    {
        if(seg[2*id][i]<seg[2*id+1][j])
        {
            seg[id].push_back(seg[2*id][i]);
            i++;
        }
        else
        {
            seg[id].push_back(seg[2*id+1][j]);
            j++;
        }
    }
    while(i<seg[2*id].size())
    {
        seg[id].push_back(seg[2*id][i]);
        i++;
    }
    while(j<seg[2*id+1].size())
    {
        seg[id].push_back(seg[2*id+1][j]);
        j++;
    }
}
int query_st(int rl,int rr,int ql,int qr,int id,int k)
{
	if(qr<rl||rr<ql||qr<ql)
	{
		return 0;
	}
	if(ql<=rl&&rr<=qr)
	{
	    int low,mid,high,flag;
	    low=0;
	    high=seg[id].size()-1;
	    while(low<=high)
	    {
	        mid=(low+high)/2;
	        if(seg[id][mid]==k)
	        {
	            return 1;
	        }
	        else if(seg[id][mid]>k)
	        {
	            high=mid-1;
	        }
	        else
	        {
	            low=mid+1;
	        }
	    }
		//if(binary_search(seg[id].begin(),seg[id].end(),k))
		{
		  //  return 1;
		}
		return 0;
	}
	int mid=(rl+rr)/2;
	int a=query_st(rl,mid,ql,qr,2*id,k);
	int b=query_st(mid+1,rr,ql,qr,2*id+1,k);
    return a|b;
}
void dfs(int u,int pp,int dep)
{
	vis[u]=1;
	par[u]=pp;
	lev[u]=dep;
	int i;
	subsize[u]=1;
	for(int i=0;i<adj[u].size();i++)
	{
		if(vis[adj[u][i].first]==0)
		{
		   // oe[indx[adj[u][i].first][i]]=adj[u][i].first;
		   // cout<<"^^^^ "<<indx[adj[u][i].first][i]<<" "<<adj[u][i].first<<endl;
			dfs(adj[u][i].first,u,dep+1);
			subsize[u]+=subsize[adj[u][i].first];
		}
	}
}
void complca(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=0;(1<<j)<n;j++)
		{
			p[i][j]=-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		p[i][0]=par[i];
	}
	for(j=1;(1<<j)<n;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(p[i][j-1]!=-1)
			{
				p[i][j]=p[p[i][j-1]][j-1];
			}
		}
	}
}
int lca(int u,int v)
{
	int tmp,logg,i;
	if(lev[u]<lev[v])
	{
		tmp=u;
		u=v;
		v=tmp;
	}
 
	for(logg=1;(1<<logg)<=lev[u];logg++);
 
	logg--;
 
    //cout<<"*** "<<u<<" "<<v<<" "<<lev[u]<<" "<<lev[v]<<endl;
	for(i=logg;i>=0;i--)
	{
		if(lev[u]-(1<<i)>=lev[v])
		{
			u=p[u][i];
		}
	}
	
	if(u==v)
	{
		return u;
	}
 
	for(i=logg;i>=0;i--)
	{
		if(p[u][i]!=-1&&p[u][i]!=p[v][i])
		{
			u=p[u][i];
			v=p[v][i];
		}
	}
	return par[u];
}
void hld(int cur,int pr)
{
	vis[cur]=1;
	if(chainhead[chainno]==-1)
	{
		chainhead[chainno]=cur;
	}
	chainind[cur]=chainno;
	chainpos[cur]=chainsize[chainno];
	chainsize[chainno]++;
	posinbase[cur]=ptr;
	arr[ptr++]=val[cur];
	int sc=-1,ncost;
	for(int i=0;i<adj[cur].size();i++)
	{
		if(vis[adj[cur][i].first]==0)
		{
			if(sc==-1 || subsize[sc] < subsize[adj[cur][i].first])
			{
				ncost=adj[cur][i].second;
				sc=adj[cur][i].first;
			}
		}
	}
	if(sc!=-1)
	{
		hld(sc,cur);
	}
	for(int i=0;i<adj[cur].size();i++)
	{
		if(vis[adj[cur][i].first]==0 && adj[cur][i].first!=sc)
		{
			chainno++;
			hld(adj[cur][i].first,cur);
		}
	}
}
int query_up(int u,int v,int n,int x)
{
	int uchain,vchain;
	uchain=chainind[u];
	vchain=chainind[v];
	int ans=0,cd;
	while(1)
	{
	    uchain=chainind[u];
		if(uchain==vchain)
		{
		    cd=query_st(1,n,posinbase[v],posinbase[u],1,x);
			ans=ans|cd;
			//cout<<"### "<<ans<<" "<<u<<" "<<v<<" "<<posinbase[v]<<" "<<posinbase[u]<<endl;
			break;
		}
		cd=query_st(1,n,posinbase[chainhead[uchain]],posinbase[u],1,x);
		ans|=cd;
	//	cout<<"*** "<<ans<<" "<<u<<" "<<chainhead[uchain]<<" "<<posinbase[chainhead[uchain]]<<" "<<posinbase[u]<<endl;
		u=chainhead[uchain];
		u=par[u];
	}
	return ans;
}
int query(int u,int v,int k,int n)
{
	int lc=lca(u,v);
	int ans=query_up(u,lc,n,k);
    ans=ans|query_up(v,lc,n,k);
    return ans;
}
int main()
{
	int t,n,i,q,a,b,w;
	int s;
//	sc(t);
	while((sc(n))!=EOF)
	{
		
		sc(q);
		ptr=1;
		//cout<<n<<endl;
		for(i=1;i<=n;i++)
		{
		    sc(a);
		    val[i]=a;
		}
		//cout<<endl;
		for(i=0;i<n-1;i++)
		{
			sc(a);
			sc(b);
			w=1;
			adj[a].push_back(mp(b,w));
			adj[b].push_back(mp(a,w));
			//indx[a].push_back(i+1);

		}
		for(i=0;i<=n;i++)
		{
			vis[i]=0;
			par[i]=-1;
			lev[i]=0;
			chainhead[i]=-1;
			chainsize[i]=0;
			subsize[i]=0;
			//oe[i]=0;
		}
		chainno=0;
		dfs(1,-1,0);
		complca(n);
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
		//	cout<<i<<" "<<par[i]<<" ";
		//	cout<<subsize[i]<<endl;
		}
		hld(1,-1);
		build(1,1,n);
		for(i=1;i<=n;i++)
		{
		   // cout<<arr[i]<<" ";
		}
	//	cout<<endl;
		//cout<<"*** "<<query_st(1,3,1,1,1)<<endl;
		while(q--)
		{
			scanf("%d%d%d",&a,&b,&s);
			int xx=query(a,b,s,n);
			if(xx)
			{
			    printf("Find\n");
			}
			else
			{
			    printf("NotFind\n");
			}
		}
		for(i=1;i<=n;i++)
	    {
	        //indx[i].clear();
	        adj[i].clear();
	    }
	    for(i=1;i<=4*n;i++)
	    {
	        seg[i].clear();
	    }
	    printf("\n");
	}
	return 0;
}
  