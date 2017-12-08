
#include <string.h>
#include <stdio.h>


int main() {
	// your code goes here
	char s[1000],p[1000];
	int n,a[100],j=0,i,l,t,r;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(1)
	{
		scanf("%s",s);
		if(strcmp(s,"-1")==0)
		{
			break;
		}
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			p[i]=s[i]+a[j++];
			r=p[i];
			if(r>=97&&r<=122)
			{
				continue;
			}
			else
			{
				t=p[i]-'z';
				p[i]='a'+t;
				p[i]--;
			}
		}
		for(i=0;i<l;i++)
		{
			printf("%c",p[i]);
		}
		printf("\n");
	}
	return 0;
}