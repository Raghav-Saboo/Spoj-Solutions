#include <iostream>
#include <math.h>
using namespace std;
#define max 500005
long long int v[max],s[max];
void pre()
{
    long int i,j,c=0,t;
    s[1]=1;
    for(i=2;i<max;i++)
    {
        if(v[i]==0)
        {
            s[i]=i+1;
            for(j=i*2;j<max;j+=i)
            {
                if(s[j]==0)
                {
                    s[j]=1;
                }
                t=j;
                c=0;
                while(t%i==0)
                {
                    t/=i;
                    c++;
                }
                s[j]*=((pow(i,c+1)-1)/(i-1));
                v[j]=1;
            }
        }
    }
}
int main()
{
    pre();
    long int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<s[n]-n<<endl;
    }
}