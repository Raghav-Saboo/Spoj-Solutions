#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
int main() {
	// your code goes here
	long long int t,n,c;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&c);
		if(c==0)
		{
			printf("Airborne wins.\n");
		}
		else
		{
			printf("Pagfloyd wins.\n");	
		}
	}
	return 0;
}