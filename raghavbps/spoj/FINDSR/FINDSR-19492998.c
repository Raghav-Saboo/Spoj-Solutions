#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[100005],ptr[100005];
map <char,int> mp,cp;
int main()
{
    int x,y,z,i,l,p,q,r;
    while(1)
    {
        scanf("%s",s);
        if(strcmp(s,"*")==0)
        {
            break;
        }
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            mp[s[i]]++;
        }
        x=0;i=0;
        while(cp.size()!=mp.size())
        {
            ptr[x++]=s[i];
            ptr[x]='\0';
            cp[s[i++]]++;
        }
        while(l%x!=0)
        {
            ptr[x++]=s[i++];
            ptr[x]='\0';
        }
      //  printf("%s %d\n",ptr,strlen(ptr));
        while(strlen(ptr)<l)
        {
            y=0;i=x;
            for(;i<l;i++)
            {
                if(ptr[y]!=s[i])
                {
                    break;
                }
                y=(y+1)%x;
            }
            if(i!=l)
            {
                i=x;
            //    printf("%d %s\n",x,ptr);
                do
                {
                    ptr[x++]=s[i++];
                    ptr[x]='\0';
                }while(l%x!=0);
               // printf("%d %s\n",x,ptr);
            }
            else
            {
                break;
            }
        }
        printf("%d\n",strlen(s)/strlen(ptr));
        mp.clear();
        cp.clear();
    }
    return 0;
}
