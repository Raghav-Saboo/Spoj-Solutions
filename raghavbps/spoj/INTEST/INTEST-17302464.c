#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	//ios_base::sync_with_stdio(false);
	int t,n,k,ans=0;
	scanf("%d%d",&t,&k);
	while(t--)
	{
		scanf("%d",&n);
		if(n%k==0)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}