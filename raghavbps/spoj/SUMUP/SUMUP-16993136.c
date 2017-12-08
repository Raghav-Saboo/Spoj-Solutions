#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,t;
	float ans;
	cin>>t;
	while(t--){
		cin>>n;
		ans=((float)(n*n+n))/(2*(n*n+n+1));
		cout<<fixed<<setprecision(5)<<ans<<endl;
	}
	return 0;
}