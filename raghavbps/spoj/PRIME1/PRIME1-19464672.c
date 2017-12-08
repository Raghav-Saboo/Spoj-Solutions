#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[100005];
vector <lli> pr;
void sieve()
{
    lli i,j;
    a[1]=1;
    a[0]=1;
    for(i=2;i<=1e5;i++)
    {
        if(!a[i])
        {
            for(j=i*i;j<=1e5;j+=i)
            {
                a[j]=1;
            }
        }
    }
    for(i=2;i<=1e5;i++)
    {
        if(!a[i])
        {
            pr.push_back(i);
        }
    }
}
int main()
{
    sieve();
    lli flag,i,j,t,aa,b;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&aa,&b);
        for(i=aa;i<=b;i++)
        {
            if(i<=1e5&&!a[i])
            {
                printf("%d\n",i);
            }
            else if(i>1e5&&i%2!=0)
            {
                flag=1;
                for(j=0;j<pr.size()&&pr[j]<=i;j++)
                {
                    if(i%pr[j]==0)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    printf("%d\n",i);
                }
            }
        }
         printf("\n");
    }
    return 0;
}
