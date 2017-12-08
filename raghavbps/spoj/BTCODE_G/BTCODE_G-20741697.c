#include <bits/stdc++.h>
using namespace std;
#define N 111111
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
int seg[4*N];
int ptr=1;
int posinbase[N];
int col[N];
int chainsize[N],chainhead[N],chainpos[N],chainind[N],chainno=0;
void build(int id,int rl,int rr)
{
    if(rl==rr)
    {
    	seg[id]=col[rl];
    	return;
    }
    int mid=(rl+rr)/2;
    build(2*id,rl,mid);
    build(2*id+1,mid+1,rr);
    if(seg[2*id]==seg[2*id+1]&&seg[id]!=0&&seg[2*id+1]!=0)
    {
        seg[id]=seg[2*id];
    }
    else
    {
        seg[id]=0;
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
	    if(seg[id])
	    {
	        return seg[id];
	    }
		return 0;
	}
	int mid=(rl+rr)/2;
	int a=query_st(rl,mid,ql,qr,2*id);
	int b=query_st(mid+1,rr,ql,qr,2*id+1);
    if(a&&b&&a==b)
    {
        return a;
    }
    else if(a==-1&&b!=-1)
    {
    	return b;
    }
    else if(b==-1&&a!=-1)
    {
    	return a;
    }
    else if(a==-1&&b==-1)
    {
    	return -1;
    }
    return 0;
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
	arr[ptr++]=col[cur];
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
int query_up(int u,int v,int n)
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
		    cd=query_st(1,n,posinbase[v],posinbase[u],1);
		    //cout<<"**** "<<u<<" "<<v<<" "<<cd<<endl;
			if(cd==0)
			{
			    return 0;
			}
			else if(ans==0)
			{
			    ans=cd;
			}
			else if(ans!=cd)
			{
			    return 0;
			}
			break;
		}
		cd=query_st(1,n,posinbase[chainhead[uchain]],posinbase[u],1);
		if(cd==0)
		{
			return 0;
		}
		else if(ans==0)
		{
	        ans=cd;
		}
		else if(ans!=cd)
		{
	        return 0;
		}
		u=chainhead[uchain];
		u=par[u];
	}
	return ans;
}
int query(int u,int v,int n)
{
	int lc=lca(u,v);
	//cout<<u<<" "<<v<<" "<<lc<<" "<<col[u]<<" "<<col[v]<<" ";
	int ans=query_up(u,lc,n);
	//cout<<ans<<" ";
    int d=query_up(v,lc,n);
    //cout<<d<<endl;
    if(ans&&d&&ans==d)
    {
        return 1;
    }
	return 0;
}
void update_st(int ui,int nv,int rl,int rr,int id)
{
	if(rl<=ui&&ui<=rr)
	{
		if(rl==rr)
		{
			seg[id]=arr[rl];
			return;
		}
		int mid=(rl+rr)/2;
		update_st(ui,nv,rl,mid,2*id);
		update_st(ui,nv,mid+1,rr,2*id+1);
        if(seg[2*id]==seg[2*id+1]&&seg[2*id]!=0&&seg[2*id+1]!=0)
        {
            seg[id]=seg[2*id];
        }
        else
        {
            seg[id]=0;
        }
	}
}
void update(int a,int b,int n)
{
    int ui=posinbase[a];
    col[a]=b;
    arr[ui]=b;
    update_st(ui,b,1,n,1);
}
int main()
{
	int t,n,i,q,a,b,w;
	int s;
//	sc(t);
	//while(t--)
	{
		sc(n);
		ptr=1;
		for(i=0;i<n-1;i++)
		{
			sc(a);
			sc(b);
			a++;
			b++;
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
			col[i]=0;
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
		}
		hld(1,-1);
		build(1,1,n);
		sc(q);
		while(q--)
		{
			scanf("%d%d%d",&s,&a,&b);
			a++;
			if(s==1)
			{
			    update(a,b,n);
			}
			else
			{
			    b++;
			    a=query(a,b,n);
			    if(a)
			    {
			        printf("YES\n");
			    }
			    else
			    {
			        printf("NO\n");
			    }
			}
		}
		for(i=1;i<=n;i++)
	    {
	        //indx[i].clear();
	        adj[i].clear();
	    }
	}
	return 0;
} 