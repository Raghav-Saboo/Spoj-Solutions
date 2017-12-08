#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define sc(x) scanf("%lld",&x)
#define pf(x) printf("%lld\n",x)
#define N 100005
struct node
{
	lli min;
	lli sum;
};
struct node seg[4*N];
lli arr[N];
void build(lli rl,lli rr,lli id)
{
	if(rl==rr)
	{
		seg[id].min=arr[rl];
		seg[id].sum=arr[rl];
		return;
	}
	lli mid=(rl+rr)/2;
	build(rl,mid,2*id);
	build(mid+1,rr,2*id+1);
	seg[id].sum=seg[2*id].sum+seg[2*id+1].sum;
	seg[id].min=min(seg[2*id].min,seg[2*id+1].min);
}
lli query_sum(lli rl,lli rr,lli ql,lli qr,lli id)
{
	if(ql>rr||rl>qr)
	{
		return 0;
	}
	if(ql<=rl&&rr<=qr)
	{
		return seg[id].sum;
	}
	lli mid=(rl+rr)/2;
	return query_sum(rl,mid,ql,qr,2*id)+query_sum(mid+1,rr,ql,qr,2*id+1);
}
lli query_min(lli rl,lli rr,lli ql,lli qr,lli id)
{
	if(ql>rr||rl>qr)
	{
		return INT_MAX;
	}
	if(ql<=rl&&rr<=qr)
	{
		return seg[id].min;
	}
	lli mid=(rl+rr)/2;
	return min(query_min(rl,mid,ql,qr,2*id),query_min(mid+1,rr,ql,qr,2*id+1));
}
void update(lli ui,lli nv,lli rl,lli rr,lli id)
{
	if(rl<=ui&&ui<=rr)
	{
		if(rl==rr)
		{
			seg[id].sum=arr[rl];
			seg[id].min=arr[rl];
			return;
		}
		lli mid=(rl+rr)/2;
		update(ui,nv,rl,mid,2*id);
		update(ui,nv,mid+1,rr,2*id+1);
		seg[id].sum=seg[2*id].sum+seg[2*id+1].sum;
		seg[id].min=min(seg[2*id].min,seg[2*id+1].min);
	}
}
int main()
{
	lli n,i,q,l,r;
	sc(n);
	for(i=1;i<=n;i++)
	{
		sc(arr[i]);
	}
	build(1,n,1);
	char s[10];
	sc(q);
	while(q--)
	{
		scanf("%s",s);
		sc(l);
		sc(r);
		if(strcmp(s,"EAT")==0)
		{
			r++;
			arr[r]-=l;
			update(r,arr[r],1,n,1);
		}
		else if(strcmp(s,"GROW")==0)
		{
			r++;
			arr[r]+=l;
			update(r,arr[r],1,n,1);
		}
		else
		{
			l++;
			r++;
			pf(query_sum(1,n,l,r,1)-query_min(1,n,l,r,1));
		}
	}
	return 0;
}