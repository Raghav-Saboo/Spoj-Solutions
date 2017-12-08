#include <iostream>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}
int main()
{
    int t;
    long long int n,a,b,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        p=gcd(a,b);
        while(p--)
        {
        	cout<<n;
        }
        cout<<endl;
    }
}
