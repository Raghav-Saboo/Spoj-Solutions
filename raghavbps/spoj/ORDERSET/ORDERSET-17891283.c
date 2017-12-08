#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct dt
{
	int v;
	int c;
};
int s,e;
int bit[200005];
struct dt tmp[200005],a[200005];
int va[200005];
char ch[200005];
void update(int ind,int v)
{
	while(ind<=e)
	{
		bit[ind]+=v;
		ind+=(ind)&(-ind);
	}
}
int query(int ind)
{
	int s=0;
	while(ind>0)
	{
		s+=bit[ind];
		ind-=(ind)&(-ind);
	}
	return s;
}
int cmp(struct dt a,struct dt b)
{
	return a.v<b.v;
}
int bsearc(int x)
{
	int l,h,mid;
	l=1;
	h=e;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(a[mid].v>=x)
		{
			h=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return l;
}
int main() {
	// your code goes here
	int w=0,q,n,i,z,l,h,mid;
	cin>>q;
	s=1;
	e=1;
	for(i=1;i<=q;i++)
	{
		cin>>ch[i]>>va[i];
		if(ch[i]=='I')
		{
			tmp[++w].v=va[i];
			tmp[w].c=0;
		}
	}
	sort(tmp+1,tmp+w+1,cmp);
	for(i=1;i<=w;i++)
	{
		if(tmp[i-1].v!=tmp[i].v)
		{
			a[e++].v=tmp[i].v;
			a[e].c=0;
		}
	}
	for(i=1;i<=q;i++)
	{
		if(ch[i]=='I')
		{
			z=bsearc(va[i]);
			a[z].c++;
			if(a[z].c==1)
			{
				update(z,1);
			}
		}
		else if(ch[i]=='D')
		{
			z=bsearc(va[i]);
			if(a[z].c>0&&a[z].v==va[i])
			{
				update(z,-1);
				a[z].c=0;
			}			
		}
		else if(ch[i]=='K')
		{
			l=1;
			h=e;
			while(l<=h)
			{
				mid=(l+h)/2;
				if(query(mid)>=va[i])
				{
					h=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			if(l>e)
			{
				cout<<"invalid\n";
			}
			else
			{
				cout<<a[l].v<<"\n";
			}
		}
		else
		{
			z=bsearc(va[i]);
			cout<<query(z-1)<<"\n";
		}
	}
	return 0;
}