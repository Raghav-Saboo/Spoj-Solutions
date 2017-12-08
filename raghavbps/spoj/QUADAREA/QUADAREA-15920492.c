#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double ans,s,a,b,c,d;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        s=(a+b+c+d)/2.0;
        ans=(s-a)*(s-b)*(s-c)*(s-d);
        ans=sqrt(ans);
        printf("%.2lf\n",ans);
    }
    return 0;
}