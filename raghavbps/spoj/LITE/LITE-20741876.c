#include <bits/stdc++.h>
using namespace std;
#define N 100000
struct node
{
	int o;
	int z;
};
struct node seg[4*N];
int lazy[4*N];
void build(int rl,int rr,int id)
{
	lazy[id]=0;
	if(rl==rr)
	{
		seg[id].o=0;
		seg[id].z=1;
		return;
	}
	int mid=(rl+rr)/2;
	build(rl,mid,2*id);
	build(mid+1,rr,2*id+1);
	seg[id].o=seg[2*id].o+seg[2*id+1].o;
	seg[id].z=seg[2*id].z+seg[2*id+1].z;
}
void update(int rl,int rr,int ql,int qr,int id)
{
	if(lazy[id]%2!=0)
	{
		int tmp;
		tmp=seg[id].o;
		seg[id].o=seg[id].z;
		seg[id].z=tmp;
		lazy[2*id]+=lazy[id];
		lazy[2*id+1]+=lazy[id];
		lazy[id]=0;
	}
	if(rl>qr||ql>rr)
	{
		return;
	}
	if(ql<=rl&&rr<=qr)
	{
		int tmp;
		tmp=seg[id].o;
		seg[id].o=seg[id].z;
		seg[id].z=tmp;
		lazy[2*id]++;
		lazy[2*id+1]++;
		return;
	}
	int mid=(rl+rr)/2;
	update(rl,mid,ql,qr,2*id);
	update(mid+1,rr,ql,qr,2*id+1);
	seg[id].o=seg[2*id].o+seg[2*id+1].o;
	seg[id].z=seg[2*id].z+seg[2*id+1].z;
}
int query(int rl,int rr,int ql,int qr,int id)
{
	if(ql>rr||rl>qr)
	{
		return 0;
	}
	if(lazy[id]%2!=0)
	{
		int tmp;
		tmp=seg[id].o;
		seg[id].o=seg[id].z;
		seg[id].z=tmp;
		lazy[2*id]+=lazy[id];
		lazy[2*id+1]+=lazy[id];
		lazy[id]=0;
	}
	if(ql<=rl&&rr<=qr)
	{
		return seg[id].o;
	}
	int mid=(rl+rr)/2;
	return query(rl,mid,ql,qr,2*id)+query(mid+1,rr,ql,qr,2*id+1);
}
int main()
{
	int n;
	int q,l,r,x;
	scanf("%d%d",&n,&q);
	build(1,n,1);
	while(q--)
	{
		scanf("%d%d%d",&x,&l,&r);
		if(x==1)
		{
			printf("%d\n",query(1,n,l,r,1));
		}
		else
		{
			update(1,n,l,r,1);
		}
	}
	return 0;
}