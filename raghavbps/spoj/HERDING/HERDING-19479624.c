#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int par[1000005];
char arr[1005][1005];
int val[1005][1005];
void make_set(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        par[i]=i;
    }
}
int fp(int x)
{
    if(x==par[x])
    {
        return x;
    }
    else
    {
        return par[x]=fp(par[x]);
    }
}
void uni(int a,int b)
{
    int pa,pb;
    pa=fp(a);
    pb=fp(b);
    if(pa!=pb)
    {
        par[pa]=pb;
    }
}
int main()
{
    int n,m,i,j,ans=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }
    int k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            val[i][j]=++k;
        }
    }
    make_set(k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j]=='N')
            {
                uni(val[i-1][j],val[i][j]);
            }
            else if(arr[i][j]=='S')
            {
                uni(val[i+1][j],val[i][j]);
            }
            else if(arr[i][j]=='E')
            {
                uni(val[i][j+1],val[i][j]);
            }
            else
            {
                uni(val[i][j-1],val[i][j]);
            }
        }
    }
    for(i=1;i<=k;i++)
    {
        if(par[i]==i)
        {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
