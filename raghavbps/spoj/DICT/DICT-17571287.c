#include <bits/stdc++.h>
using namespace std;
int g;
struct trie
    {
    int pr;
    int lf;
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
    p->lf=0;
    return p;
}
void insert(struct trie *root,char x[])
    {
    int i,l;
    l=strlen(x);
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
    t->lf=1;
}
struct trie *ser(struct trie *root,char x[])
    {
    int i,l,f=1;
    l=strlen(x);
    struct trie *t=root;
    for(i=0;i<l&&t!=NULL;i++)
        {
            if(t->c[x[i]-'a']!=NULL)
                {
                t=t->c[x[i]-'a'];
            }
            else
            {
            	f=0;
            }
    }
    if(!f)
    {
    	t=NULL;
    }
    return t;
}
void pr(struct trie *w,char y[],int i)
{
	for(;i<26;i++)
	{
		char z[25];
		if(w->c[i]!=NULL)
		{
			char c=i+'a';
			strcpy(z,y);
			int l=strlen(z);
			z[l]=c;
			z[l+1]='\0';
			if(w->c[i]->lf==1)
			{
				g=1;
				printf("%s\n",z);
			}
			pr(w->c[i],z,0);
		}
	}
}
int main() {
    int n,i;
    char x[25],y[25];
    scanf("%d",&n);
    struct trie *root=getnode();
    struct trie *w;
    while(n--)
    {
        scanf("%s",x);
        insert(root,x);
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    	g=0;
    	scanf("%s",x);
    	w=ser(root,x);
    	printf("Case #%d:\n",i);
    	if(w==NULL||(w->pr==0))
    	{
    		printf("No match.\n");
    	}
    	else
    	{
    		strcpy(y,x);
    		y[strlen(y)]='\0';
    		pr(w,y,0);
    		if(g==0)
    		{
    			printf("No match.\n");
    		}
    	}
    }
    return 0;
}

