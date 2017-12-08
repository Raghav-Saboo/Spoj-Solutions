#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1026][1026];
int tr[1026][1026];
int max_x,max_y;
void update(int x,int y,int v)
{
	int w=tr[x][y];
	int y1;
	while(x<=max_x)
	{
		y1=y;
		while(y1<=max_y)
		{
			a[x][y1]+=v-w;
			y1+=(y1)&(-y1);
		}
		x+=(x)&(-x);
	}
}
int query(int x,int y)
{
	int s=0,y1;
	while(x>0)
	{
		y1=y;
		while(y1>0)
		{
			s+=a[x][y1];
			y1-=(y1)&(-y1);
		}
		x-=(x)&(-x);
	}
	return s;
}
int main() {
	// your code goes here
	int x1,y1,v,i,j,w,t,x2,y2,ans,n;
	char s[10];
	scanf("%d",&t);
	for(w=1;w<=t;w++)
	{
		scanf("%d",&n);
		max_x=n;
		max_y=n;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				a[i][j]=0;
				tr[i][j]=0;
			}
		}
		while(1)
		{
			scanf("%s",s);
			if(strcmp(s,"END")==0)
			{
				break;
			}
			if(strcmp(s,"SET")==0)
			{
				scanf("%d%d%d",&x1,&y1,&v);
				x1++;
				y1++;
				update(x1,y1,v);
				tr[x1][y1]=v;
			}
			else if(strcmp(s,"SUM")==0)
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				x1++;
				x2++;
				y1++;
				y2++;
				ans=0;
				ans+=query(x2,y2);
				ans-=query(x2,y1-1);
				ans-=query(x1-1,y2);
				ans+=query(x1-1,y1-1);
				printf("%d\n",ans);
			}
		}
		printf("\n");
	}
	return 0;
}