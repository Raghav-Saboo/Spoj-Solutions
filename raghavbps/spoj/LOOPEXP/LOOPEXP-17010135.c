#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double arr[1000005];
void pre()
{
	long int i;
	arr[1]=1;
	for(i=2;i<=1000000;i++)
	{
		arr[i]=arr[i-1]+1.0/i;
	}
}
int main() {
	// your code goes here
	pre();
	int t;
	long int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		printf("%lf\n",arr[n]);
	}
	return 0;
}