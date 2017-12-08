#include <iostream>
using namespace std;
#include <math.h>
#define n 1000005
long long int fn[n],an[n],v[n];
void fun()
{
    long int i,j,c,t;
    for(i = 2; i < n; i++)
    {
        if(v[i] == 0)
        {
            fn[i]=i+1;
            for(j = i*2; j < n; j+=i)
            {
                t=j;
                c=0;
                if(fn[j]==0)
                {
                    fn[j]=1;
                }
                while(t%i == 0)
                {
                    c++;
                    t=t/i;
                }
                fn[j]*=((pow(i,c+1)-1))/(i-1);
                v[j]=1;
            }
        }
    }
}
void pre()
{
    long int i;
    for(i = 2;i < n; i++)
    {
        an[i]=an[i-1]+fn[i]-i;
    }
}
int main()
{
	fun();
	pre();
    int t;
    long int nn;
    cin>>t;
    while(t--)
    {
        cin>>nn;
        cout<<an[nn]<<endl;
    }
}
