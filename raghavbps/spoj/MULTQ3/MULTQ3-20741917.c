#include <bits/stdc++.h>
using namespace std;
#define N 1000000
struct node
{
	int r0;
	int r1;
	int r2;
};
struct node seg[4*N];
int lazy[4*N];
void build(int rl,int rr,int id)
{
	lazy[id]=0;
	if(rl==rr)
	{
		seg[id].r0=1;
		seg[id].r1=0;
		seg[id].r2=0;
		return;
	}
	int mid=(rl+rr)/2;
	build(rl,mid,2*id);
	build(mid+1,rr,2*id+1);
	seg[id].r0=seg[2*id].r0+seg[2*id+1].r0;
	seg[id].r1=seg[2*id].r1+seg[2*id+1].r1;
	seg[id].r2=seg[2*id].r2+seg[2*id+1].r2;
}
void update(int rl,int rr,int ql,int qr,int id)
{
	if(lazy[id]%3!=0)
	{
		int rm=lazy[id]%3;
		if(rm==1)
		{
			int x,y,z;
			x=seg[id].r0;
			y=seg[id].r1;
			z=seg[id].r2;
			seg[id].r0=z;
			seg[id].r1=x;
			seg[id].r2=y;
		}
		else if(rm==2)
		{
			int x,y,z;
			x=seg[id].r0;
			y=seg[id].r1;
			z=seg[id].r2;
			seg[id].r0=y;
			seg[id].r1=z;
			seg[id].r2=x;			
		}
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
		int x,y,z;
		x=seg[id].r0;
		y=seg[id].r1;
		z=seg[id].r2;
		seg[id].r0=z;
		seg[id].r1=x;
		seg[id].r2=y;
		lazy[2*id]++;
		lazy[2*id+1]++;
		return;
	}
	int mid=(rl+rr)/2;
	update(rl,mid,ql,qr,2*id);
	update(mid+1,rr,ql,qr,2*id+1);
	seg[id].r0=seg[2*id].r0+seg[2*id+1].r0;
	seg[id].r1=seg[2*id].r1+seg[2*id+1].r1;
	seg[id].r2=seg[2*id].r2+seg[2*id+1].r2;
}
int query(int rl,int rr,int ql,int qr,int id)
{
	if(ql>rr||rl>qr)
	{
		return 0;
	}
	if(lazy[id]%3!=0)
	{
		int rm=lazy[id]%3;
		if(rm==1)
		{
			int x,y,z;
			x=seg[id].r0;
			y=seg[id].r1;
			z=seg[id].r2;
			seg[id].r0=z;
			seg[id].r1=x;
			seg[id].r2=y;
		}
		else if(rm==2)
		{
			int x,y,z;
			x=seg[id].r0;
			y=seg[id].r1;
			z=seg[id].r2;
			seg[id].r0=y;
			seg[id].r1=z;
			seg[id].r2=x;			
		}
		lazy[2*id]+=lazy[id];
		lazy[2*id+1]+=lazy[id];
		lazy[id]=0;
	}
	if(ql<=rl&&rr<=qr)
	{
		return seg[id].r0;
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
		l++;
		r++;
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