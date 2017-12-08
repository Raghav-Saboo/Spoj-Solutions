#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int t,n,x,a1,a2;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a1=pow(2,n-1);
		a2=a1+(a1*(n-1))/2;
		cout<<a1<<" "<<a2<<endl;
	}
	return 0;
}