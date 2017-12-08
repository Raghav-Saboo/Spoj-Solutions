#include <bits/stdc++.h>
using namespace std;
#define N 100000
#define ln 30
#define sc(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
#define pii pair<int,int>
#define mp make_pair
vector <pii> adj[N];
map <pii,int> vp;
int col[N];
int ap[N][2];
int par[N];
int subsize[N];
int lev[N];
int p[N][ln];
int vis[N];
//vector <int> indx[N];
int arr[N];
int seg[4*N];
int ptr=1;
int oe[N];
int posinbase[N];
int chainsize[N],chainhead[N],chainpos[N],chainind[N],chainno=0;
void build(int id,int rl,int rr)
{
    if(rl==rr)
    {
    	seg[id]=(col[rl]==1)?arr[rl]:-1;
    	return;
    }
    int mid=(rl+rr)/2;
    build(2*id,rl,mid);
    build(2*id+1,mid+1,rr);
    if(seg[2*id]!=-1)
    {
        seg[id]=seg[2*id];
    }
    else
    {
        seg[id]=seg[2*id+1];
    }
    //cout<<"*** "<<id<<" "<<seg[id]<<endl;
}
void update(int ui,int nv,int rl,int rr,int id)
{
	if(rl<=ui&&ui<=rr)
	{
		if(rl==rr)
		{
			seg[id]=(col[rl]==1)?arr[rl]:-1;
			return;
		}
		int mid=(rl+rr)/2;
		update(ui,nv,rl,mid,2*id);
		update(ui,nv,mid+1,rr,2*id+1);
        if(seg[2*id]!=-1)
        {
            seg[id]=seg[2*id];
        }
        else
        {
            seg[id]=seg[2*id+1];
        }
	}
}
int query_st(int rl,int rr,int ql,int qr,int id)
{
	if(qr<rl||rr<ql||qr<ql)
	{
		return -1;
	}
	if(ql<=rl&&rr<=qr)
	{
		return seg[id];
	}
	int mid=(rl+rr)/2;
	int lf=query_st(rl,mid,ql,qr,2*id);
	int rf=query_st(mid+1,rr,ql,qr,2*id+1);
	if(lf!=-1)
	{
	    return lf;
	}
	else
	{
	    return rf;
	}
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
	arr[ptr++]=cur;
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
int change(int a,int n)
{
    int ui=posinbase[a];
	col[ui]=1-col[ui];
//	cout<<ui<<" **** "<<oe[a]<<" "<<b<<endl;
	update(ui,col[ui],1,n,1);
}
int query_up(int u,int v,int n)
{
	int uchain,vchain;
	uchain=chainind[u];
	vchain=chainind[v];
	int ans=-1,cd;
	while(1)
	{
	    uchain=chainind[u];
		if(uchain==vchain)
		{
		    cd=query_st(1,n,posinbase[v],posinbase[u],1);
			if(cd!=-1)
			{
			    ans=cd;
			}
			//cout<<"### "<<ans<<" "<<u<<" "<<v<<" "<<posinbase[v]<<" "<<posinbase[u]<<endl;
			break;
		}
		cd=query_st(1,n,posinbase[chainhead[uchain]],posinbase[u],1);
		if(cd!=-1)
		{
	        ans=cd;
		}
	//	cout<<"*** "<<ans<<" "<<u<<" "<<chainhead[uchain]<<" "<<posinbase[chainhead[uchain]]<<" "<<posinbase[u]<<endl;
		u=chainhead[uchain];
		u=par[u];
	}
	return ans;
}
int query(int u,int v,int n)
{
	int lc=lca(u,v);
	int ans=query_up(u,lc,n);
	if(ans==-1)
	{
	    ans=query_up(v,lc,n);
	}
	return ans;
}
int main()
{
	int t,n,i,q,a,b,w;
	int s;
//	sc(t);
	//while(t--)
	{
		sc(n);
		sc(q);
		ptr=1;
		//cout<<n<<endl;
		
		for(i=0;i<n-1;i++)
		{
			sc(a);
			sc(b);
			w=1;
			adj[a].push_back(mp(b,w));
			adj[b].push_back(mp(a,w));
			//indx[a].push_back(i+1);
		//	indx[b].push_back(i+1);
			//oe[i+1]=b;
			ap[i+1][0]=a;
			ap[i+1][1]=b;
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
			scanf("%d%d",&s,&a);
			if(s==0)
			{
				change(a,n);
			}
			else
			{
				printf("%d\n",query(1,a,n));
			}
		}
		for(i=1;i<=n;i++)
	    {
	        //indx[i].clear();
	        adj[i].clear();
	    }
	    vp.clear();
	}
	return 0;
}
 