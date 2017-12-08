#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>
int main() {
	// your code goes here
	int t,r;
	double v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&r);
		v=(2-sqrt(2))*8*r*r*r;
		printf("%.4lf\n",v);
	}
	return 0;
}