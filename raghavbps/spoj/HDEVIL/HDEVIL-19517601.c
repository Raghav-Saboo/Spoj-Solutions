#include <iostream>
#include <bits/stdc++.h>
using namespace std;
set <int> st;
void pre()
{
    int a,b,c;
    a=0;
    b=1;
    st.insert(a);
    st.insert(b);
    c=a+b;
    while(c<=1e8)
    {
        //cout<<c<<" ";
        st.insert(c);
        a=b;
        b=c;
        c=a+b;
    }
    cout<<"\n";
}
int main()
{
    pre();
    int p=1,t,n,m,i,sn,sm;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        sn=0;
        for(i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                sn+=i;
                if(n!=n/i&&i!=n/i)
                {
                    sn+=n/i;
                }
            }
        }
    //    cout<<n<<" "<<sn<<endl;
        sm=0;
        m=sn%m;
        for(i=1;i*i<=m;i++)
        {
            if(m%i==0)
            {
                sm++;
                if(m!=m/i&&i!=m/i)
                {
                    sm++;
                }
            }
        }
      //  cout<<m<<" "<<sm<<endl;
        cout<<"Case #"<<p<<" : ";
        if(st.find(sm)!=st.end())
        {
            cout<<"YES.\n";
        }
        else
        {
            cout<<"NO.\n";
        }
        p++;
    }
    return 0;
}
