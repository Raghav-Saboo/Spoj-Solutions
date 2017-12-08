#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[105][105],b[105][105];
int main() {
	// your code goes here
	lli q,n,i,j,k,rn,cn,s,ans=0,sa=0,sb=0;
	char ch;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lld",&b[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				ans+=a[i][k]*b[k][j];
			}
		}
	}
	//cout<<sa<<" "<<sb<<" "<<ans<<endl;
	scanf("%lld",&q);
	while(q--)
	{
		scanf(" %c%lld%lld%lld",&ch,&rn,&cn,&s);
		if(ch=='A')
		{
			sb=0;
			for(i=0;i<n;i++)
			{
				sb+=b[cn][i];
			}
			ans=ans+sb*s-sb*a[rn][cn];
			a[rn][cn]=s;
		}
		else
		{
			sa=0;
			for(i=0;i<n;i++)
			{
				sa+=a[i][rn];
			}
			ans=ans+sa*s-sa*b[rn][cn];
			b[rn][cn]=s;
		}
		printf("%lld\n",ans);
	}
	return 0;
}