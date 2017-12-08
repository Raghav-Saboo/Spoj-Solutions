#include <iostream>
using namespace std;
int a[200005];
long long int bit[10000005];
void add(int ind,int n,int v)
{
	while(ind<=n)
	{
		bit[ind]+=v;
		ind+=(ind&(-ind));
	}
}
long long int que(int ind)
{
	long long int s=0;
	while(ind>0)
	{
		s+=bit[ind];
		ind-=(ind&(-ind));
	}
	return s;
}
int main()
{
    int n,i,t,mn;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	mn=0;
	 	for(i=1;i<=n;i++)
    	{
    		cin>>a[i];
    		if(mn<a[i])
    		{
    			mn=a[i];
    		}
    	}
    	for(i=1;i<=mn;i++)
    	{
    		bit[i]=0;
    	}
    	long long int ans=0;
    	for(i=1;i<=n;i++)
    	{
    	    if(a[i]==0)
    	    {
    	        continue;
    	    }
    		long long int w=que(a[i]-1);
    	//	cout<<w<<" ";
    		ans+=w;
    		add(a[i],mn,a[i]);
    	}
    	for(i=1;i<=n;i++)
    	{
    		//cout<<bit[i]<<" ";
    	}
    	cout<<ans<<endl;
    }
    return 0;
}