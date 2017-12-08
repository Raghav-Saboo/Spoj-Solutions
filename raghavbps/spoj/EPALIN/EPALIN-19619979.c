#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char ch[200005];
int pi[200005];
int pref(string s)
{
    int k,q,m;
    pi[1]=0;
    k=0;
    m=s.size();
    for(q=2;q<=m;q++)
    {
        while(k>0&&s[k]!=s[q-1])
        {
            k=pi[k];
        }
        if(s[k]==s[q-1])
        {
            k++;
        }
        pi[q]=k;
    }
    return pi[m];
}
int main()
{
    int t,i,l,x;
    string s,y;
    while((scanf("%s",ch))!=EOF)
    {
        s="";
        l=strlen(ch);
        for(i=0;i<l;i++)
        {
            s+=ch[i];
        }
        y=s;
        reverse(s.begin(),s.end());
        x=pref(s+y);
       // printf("%d ",x);
        printf("%s",ch);
        for(i=l-x-1;i>=0;i--)
        {
            printf("%c",ch[i]);
        }
        printf("\n");
    }
    return 0;
}
