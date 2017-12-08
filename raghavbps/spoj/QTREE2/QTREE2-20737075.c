#include <bits/stdc++.h>
using namespace std;
#define N 100000
#define ln 24
#define sc(x) scanf("%lld",&x)
#define pf(x) printf("%lld\n",x)
#define pii pair<long long int,long long int>
#define mp make_pair
vector <pii> adj[N];
long long int par[N];
long long int subsize[N];
long long int lev[N];
long long int p[N][ln];
long long int vis[N];
long long int arr[N];
long long int seg[4*N];
long long int ptr=1;
long long int posinbase[N];
long long int chainsize[N],chainhead[N],chainpos[N],chainind[N],chainno=0;
void build(long long int id,long long int rl,long long int rr)
{
    if(rl==rr)
    {
    	seg[id]=arr[rl];
    	return;
    }
    long long int mid=(rl+rr)/2;
    build(2*id,rl,mid);
    build(2*id+1,mid+1,rr);
    seg[id]=seg[2*id]+seg[2*id+1];
}
void update(long long int ui,long long int nv,long long int rl,long long int rr,long long int id)
{
	if(rl<=ui&&ui<=rr)
	{
		if(rl==rr)
		{
			seg[id]=arr[rl];
			return;
		}
		long long int mid=(rl+rr)/2;
		update(ui,nv,rl,mid,2*id);
		update(ui,nv,mid+1,rr,2*id+1);
		seg[id]=seg[2*id]+seg[2*id+1];
	}
}
long long int query_st(long long int rl,long long int rr,long long int ql,long long int qr,long long int id)
{
	if(qr<rl||rr<ql||qr<ql)
	{
		return 0;
	}
	if(ql<=rl&&rr<=qr)
	{
		return seg[id];
	}
	long long int mid=(rl+rr)/2;
	return (query_st(rl,mid,ql,qr,2*id)+query_st(mid+1,rr,ql,qr,2*id+1));
}
void dfs(long long int u,long long int pp,long long int dep)
{
	vis[u]=1;
	par[u]=pp;
	lev[u]=dep;
	long long int i;
	subsize[u]=1;
	for(long long int i=0;i<adj[u].size();i++)
	{
		if(vis[adj[u][i].first]==0)
		{
			dfs(adj[u][i].first,u,dep+1);
			subsize[u]+=subsize[adj[u][i].first];
		}
	}
}
void complca(long long int n)
{
	long long int i,j;
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
long long int lca(long long int u,long long int v)
{
	long long int tmp,logg,i;
	if(lev[u]<lev[v])
	{
		tmp=u;
		u=v;
		v=tmp;
	}
 
	for(logg=1;(1<<logg)<=lev[u];logg++);
 
	logg--;
	
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
void hld(long long int cur,long long int cost,long long int pr)
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
	arr[ptr++]=cost;
	long long int sc=-1,ncost;
	for(long long int i=0;i<adj[cur].size();i++)
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
		hld(sc,ncost,cur);
	}
	for(long long int i=0;i<adj[cur].size();i++)
	{
		if(vis[adj[cur][i].first]==0 && adj[cur][i].first!=sc)
		{
			chainno++;
			hld(adj[cur][i].first,adj[cur][i].second,cur);
		}
	}
}
long long int query_up(long long int u,long long int v,long long int n)
{
	long long int uchain,vchain;
	uchain=chainind[u];
	vchain=chainind[v];
	long long int ans=0;
	while(1)
	{
	    uchain=chainind[u];
		if(uchain==vchain)
		{
			ans+=query_st(1,n,posinbase[v]+1,posinbase[u],1);
			break;
		}
		ans+=query_st(1,n,posinbase[chainhead[uchain]],posinbase[u],1);
		u=chainhead[uchain];
		u=par[u];
	}
	return ans;
}
long long int query(long long int u,long long int v,long long int n)
{
	long long int lc=lca(u,v);
	long long int ans=query_up(u,lc,n);
	ans+=query_up(v,lc,n);
	return ans;
}
int main()
{
	long long int t,n,i,q,a,b,w;
	char s[105];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
	//	cout<<n<<" "<<t<<endl;
		ptr=1;
		
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&w);
			adj[a].push_back(mp(b,w));
			adj[b].push_back(mp(a,w));
		}
		for(i=0;i<=n;i++)
		{
			vis[i]=0;
			par[i]=-1;
			lev[i]=0;
			chainhead[i]=-1;
			chainsize[i]=0;
			subsize[i]=0;
		}
		chainno=0;
		dfs(1,-1,0);
		complca(n);
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		hld(1,0,-1);
		build(1,1,n);
		while(1)
		{
			scanf("%s",s);
			//cout<<s<<endl;
			if(strcmp(s,"DONE")==0)
			{
				break;
			}
			if(strcmp(s,"KTH")==0)
			{
			    long long int k;
			    scanf("%lld%lld%lld",&a,&b,&k);
				long long int lc=lca(a,b);
				long long int ans;
				if(lc==-1)
				{
				    ans=b;
				}
				else
				{
				    ans=a;
				    long long int td=(lev[a]-lev[lc]+1)+(lev[b]-lev[lc]);
				    if(k>td)
				    {
				        ans=b;
				    }
				    else
				    {
				        if(lev[a]-lev[lc]+1>=k)
				        {
				            long long int cp=0;
				            k--;
				            while(k>0)
				            {
				                if(k%2&&ans!=-1)
				                {
				                    ans=p[ans][cp];
				                }
				                k/=2;
				                cp++;
				            }
				        }
				        else
				        {
				            ans=b;
				            k=(lev[b]+lev[a]-2*lev[lc]+2)-k;
				            long long int cp=0;
				            k--;
				            while(k>0)
				            {
				                if(k%2&&ans!=-1)
				                {
				                    ans=p[ans][cp];
				                }
				                k/=2;
				                cp++;
				            }
				        }
				    }
				}
			    pf(ans);
			}
			else
			{
			    scanf("%lld%lld",&a,&b);
				printf("%lld\n",query(a,1,n)+query(1,b,n)-2*query(1,lca(a,b),n));
			}
		}
		for(i=1;i<=n;i++)
	    {
	        adj[i].clear();
	    }
	    printf("\n");
	}
	return 0;
}   