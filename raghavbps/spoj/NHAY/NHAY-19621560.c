#include<bits/stdc++.h>
using namespace std;
int pi[1000005];
char ch1[1000005];
char ch2[1000005];
int main(){
	int i,q,k,l,m;
	while(scanf("%d",&m)!=EOF)
	{
	    scanf("%s%s",&ch1,&ch2);
	    pi[1]=0;
	    k=0;
	    for(q=2;q<=m;q++)
	    {
	        while(k>0&&ch1[k]!=ch1[q-1])
	        {
	            k=pi[k];
	        }
	        if(ch1[k]==ch1[q-1])
	        {
	            k++;
	        }
	        pi[q]=k;
	    }
	    l=strlen(ch2);
	    q=0;
	    for(i=1;i<=l;i++)
	    {
	        while(q>0&&ch1[q]!=ch2[i-1])
	        {
	            q=pi[q];
	        }
	        if(ch1[q]==ch2[i-1])
	        {
	            q++;
	        }
	        if(q==m)
	        {
	            printf("%d\n",i-m);
	            q=pi[q];
	        }
	    }
	    printf("\n");
	}
}