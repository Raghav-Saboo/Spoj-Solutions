#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define sc(x) scanf("%lld",&x)
#define pf(x) printf("%lld\n",x)
lli tmp[10005];
int main() {
	// your code goes here
	lli t,n,u,l,r,v,q,id,i;
	sc(t);
	while(t--)
	{
		sc(n);
		sc(u);
		memset(tmp,0,sizeof(tmp));
		while(u--)
		{
			sc(l);sc(r);sc(v);
			l++;
			r++;
			tmp[l]+=v;
			tmp[r+1]-=v;
		}
		for(i=1;i<=n;i++)
		{
			tmp[i]+=tmp[i-1];
		}
		sc(q);
		while(q--)
		{
			sc(id);
			id++;
			pf(tmp[id]);
		}
	}
	return 0;
}