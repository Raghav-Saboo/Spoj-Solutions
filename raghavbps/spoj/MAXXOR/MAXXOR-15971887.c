#include <iostream>
using namespace std;
#include <math.h>
int main() {
	// your code goes here
	long long int l,r,ans;
	scanf("%lld%lld",&l,&r);
	ans=pow( 2,ceil( log(r)/log(2) ) )-1 ;
	printf("%lld",ans);
	return 0;
}