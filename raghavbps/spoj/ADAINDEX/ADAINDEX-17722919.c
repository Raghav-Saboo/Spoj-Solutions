#include <bits/stdc++.h>
using namespace std;
struct trie
    {
    int pr;
    struct trie *c[26];
};
struct trie *getnode()
    {
    int i;
    struct trie *p=(struct trie *)malloc(sizeof(struct trie));
    for(i=0;i<26;i++)
        {
        p->c[i]=NULL;
    }
    p->pr=0;
    return p;
}
void insert(struct trie *root,string x)
    {
    int i,l;
    l=x.size();
    struct trie *t=root;
    for(i=0;i<l&&t!=NULL;i++)
        {
        if(t->c[x[i]-'a']==NULL)
            {
            t->c[x[i]-'a']=getnode();
        }
        t=t->c[x[i]-'a'];
        (t->pr)++;
    }
}
int ser(struct trie *root,string x)
    {
    int i,l;
    l=x.size();
    struct trie *t=root;
    for(i=0;i<l&&t!=NULL;i++)
        {
            if(t->c[x[i]-'a']!=NULL)
                {
                t=t->c[x[i]-'a'];
            }
        else
            {
            return 0;
        }
        //(t->pr)++;
    }
    return t->pr;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	std::ios::sync_with_stdio(false); 
    int n,q;
    string x,y;
    cin>>n>>q;
    struct trie *root=getnode();
    while(n--)
    {
        cin>>x;
		insert(root,x);
    }
    while(q--)
    {
    	cin>>y;
    	cout<<ser(root,y)<<endl;
    }
    return 0;
}