#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lint long long int
struct trie
{
    struct trie *c[2];
    lint lc;
    lint rc;
};
lint a[100005];
string ntob(lint n)
{
    string s="",ans="";
    lint x;
    if(n>0)
    {
        x=log2(n)+1;
    }
    else
    {
        x=0;
    }
    for(int i=x;i<20;i++)
    {
        s+="0";
    }
    while(n>0)
    {
        if(n%2==0)
        {
            ans+="0";
        }
        else
        {
            ans+="1";
        }
        n/=2;
    }
    reverse(ans.begin(),ans.end());
    return s+ans;
}
struct trie *getnewnode()
{
    struct trie *tmp=new struct trie();
    tmp->c[0]=NULL;
    tmp->c[1]=NULL;
    tmp->lc=0;
    tmp->rc=0;
    return tmp;
}
void insert(struct trie *root,string s)
{
    lint i,l=s.size();
    struct trie *tmp=root;
    for(i=0;i<l;i++)
    {
        if((s[i]-'0')==0)
        {
            tmp->lc++;
        }
        else
        {
            tmp->rc++;
        }
        if(tmp!=NULL&&tmp->c[s[i]-'0']==NULL)
        {
            tmp->c[s[i]-'0']=getnewnode();
        }
        if(tmp!=NULL)
        {
            tmp=tmp->c[s[i]-'0'];
        }
    }
}
lint query(struct trie *root,string s,lint k)
{
    lint i,l=s.size(),x=0;
    struct trie *tmp=root;
    string g=ntob(k);
    for(i=0;i<l;i++)
    {
        if(g[i]=='1'&&s[i]=='1')
        {
            x+=tmp->rc;
            tmp=tmp->c[0];
            if(tmp==NULL)
            {
                return x;
            }
        }
        else if(g[i]=='0'&&s[i]=='0')
        {
            tmp=tmp->c[0];
            if(tmp==NULL)
            {
                return x;
            }
        }
        else if(g[i]=='1'&&s[i]=='0')
        {
            x+=tmp->lc;
            tmp=tmp->c[1];
            if(tmp==NULL)
            {
                return x;
            }
        }
        else
        {
            tmp=tmp->c[1];
            if(tmp==NULL)
            {
                return x;
            }
        }
    }
    return x;
}
int main()
{
    struct trie *root;
    lint t,n,i,ans,p,q,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        p=0;
        ans=0;
        root=getnewnode();
        insert(root,ntob(0));
        for(i=1;i<=n;i++)
        {
            q=p^a[i];
            ans+=query(root,ntob(q),k);
            insert(root,ntob(q));
            p=q;
        }
        cout<<ans<<endl;
    }
    return 0;
}
