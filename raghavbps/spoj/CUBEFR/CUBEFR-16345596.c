#include <bits/stdc++.h>
using namespace std;
#define max 1000005
long int cf[max],v[max],pcf[max];
void sieve()
{
    long int i,j,c,t;
    for(i=2;i*i*i<max;i++)
    {
    	if(v[i]==0)
    	{
            for(j=i*2;j<max;j+=i)
            {
                if(cf[j]==0)
                {
                    t=j;
                    c=0;
                    while(t%i==0)
                    {
                        t/=i;
                        c++;
                    }
                    if(c>=3)
                    {
                        cf[j]=1;
                    }
                }
            }
    	}
    }
}
void pre()
{
    long int i,p=2;
    pcf[1]=1;
    for(i=2;i<max;i++)
    {
        if(cf[i]==0)
        {
            pcf[i]=p++;
        }
    }
}
int main()
{
    sieve();
    pre();
    long int t,n,i=0;
    cin>>t;
    while(t--)
    {
        i++;
        cin>>n;
        if(cf[n]==0)
        {
            cout<<"Case "<<i<<": "<<pcf[n]<<endl;
        }
        else
        {
            cout<<"Case "<<i<<": "<<"Not Cube Free"<<endl;
        }
    }
}
