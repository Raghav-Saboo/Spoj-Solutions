#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	char s[205],ans[205];
	int i,l,j,flag,p,c,w;
	while(scanf("%s",s)!=EOF)
	{
		l=strlen(s);
		flag=1;c=0;j=0;
		if(!(s[0]>=97&&s[0]<=122))
		{
			flag=0;
		}
		for(i=1;i<l;i++)
		{
			if(s[i]=='_')
			{
				c++;
			}
			if(s[i]>=65&&s[i]<=90)
			{
				j++;
			}
			if(s[i]=='_'&&i==l-1)
			{
				flag=0;
			}
		}
		if(c>0&&j>0)
		{
			flag=0;
		}
		if(flag&&c>0)
		{
			w=0;
			for(i=1;i<l;i++)
			{
				if(s[i-1]=='_'&&s[i]!='_')
				{
					w++;
				}
			}
			if(w!=c)
			{
				flag=0;
			}
		}
		if(flag)
		{
			p=0;
			if(j==0)
			{
				ans[p++]=s[0];
				for(i=1;i<l;i++)
				{
					if(s[i]=='_')
					{
						s[i+1]=s[i+1]-32;
					}
					else
					{
						ans[p++]=s[i];
					}
				}
				ans[p]='\0';
				printf("%s\n",ans);
			}
			else
			{
				ans[p++]=s[0];
				for(i=1;i<l;i++)
				{
					if(s[i]>=65&&s[i]<=90)
					{
						ans[p++]='_';
						s[i]=s[i]+32;
					}
					ans[p++]=s[i];
				}
				ans[p]='\0';
				printf("%s\n",ans);
			}
		}
		else
		{
			printf("Error!\n");
		}
	}
	return 0;
}